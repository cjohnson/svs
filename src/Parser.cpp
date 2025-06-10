#include <vector>

#include "Parser.h"

svs::ParseResult<char> svs::Parser::parse_character(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end,
    const char _match_character)
{
    if (_begin == _end || *_begin != _match_character)
    {
        return svs::ParseResult<char>::fail();
    }

    return svs::ParseResult<char>::succeed(*_begin, _begin + 1);
}

svs::ParseResult<char> svs::Parser::parse_character(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end,
    const std::unordered_set<char>& _match_character_set)
{
    if (_begin == _end || _match_character_set.find(*_begin) == _match_character_set.end())
    {
        return svs::ParseResult<char>::fail();
    }

    return svs::ParseResult<char>::succeed(*_begin, _begin + 1);
}

svs::ParseResult<std::string> svs::Parser::parse_string(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end,
    const std::string& _match_string)
{
    std::string::const_iterator source_it = _begin;
    std::string::const_iterator match_it = _match_string.begin();

    if (match_it == _match_string.end())
    {
        if (source_it == _end)
        {
            return svs::ParseResult<std::string>::succeed(_match_string, source_it);
        }
        else
        {
            return svs::ParseResult<std::string>::fail();
        }
    }

    svs::ParseResult<char> char_result = parse_character(source_it, _end, *match_it);
    while (char_result.succeeded())
    {
        ++source_it;
        ++match_it;

        if (match_it == _match_string.end())
        {
            return svs::ParseResult<std::string>::succeed(_match_string, source_it);
        }

        char_result = parse_character(source_it, _end, *match_it);
    }

    return svs::ParseResult<std::string>::fail();
}

svs::ParseResult<std::string> svs::Parser::parse_whitespace(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    if (_begin == _end || !std::isspace(*_begin))
    {
        return svs::ParseResult<std::string>::fail();
    }

    std::string::const_iterator it = _begin;
    std::stringstream ss;

    while (it != _end && std::isspace(*it))
    {
        ss << *it;
        ++it;
    }
    return svs::ParseResult<std::string>::succeed(ss.str(), it);
}

svs::ParseResult<std::string> svs::Parser::parse_line(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    std::string::const_iterator it = _begin;
    std::stringstream ss;

    while (it != _end)
    {
        if (*it == '\n')
        {
            ++it;
            return svs::ParseResult<std::string>::succeed(ss.str(), it);
        }

        if (*it == '\r')
        {
            ++it;
            if (it != _end && *it == '\n')
            {
                ++it;
            }
            return svs::ParseResult<std::string>::succeed(ss.str(), it);
        }

        ss << *it;
        ++it;
    }

    return svs::ParseResult<std::string>::succeed(ss.str(), it);
}

svs::ParseResult<std::string> svs::CommentParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    svs::ParseResult<std::string> one_line_result = parse_one_line_comment(_begin, _end);
    if (one_line_result.succeeded())
    {
        return one_line_result;
    }

    svs::ParseResult<std::string> block_result = parse_block_comment(_begin, _end);
    if (block_result.succeeded())
    {
        return block_result;
    }

    return svs::ParseResult<std::string>::fail();
}

svs::ParseResult<std::string> svs::CommentParser::parse_one_line_comment(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    std::string::const_iterator it = _begin;

    svs::ParseResult<std::string> start_syntax_result = parse_string(it, _end, "//");
    if (!start_syntax_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = start_syntax_result.next();

    svs::ParseResult<std::string> comment_line_result = parse_line(it, _end);
    if (!comment_line_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = comment_line_result.next();

    return svs::ParseResult<std::string>::succeed(comment_line_result.value(), it);
}

svs::ParseResult<std::string> svs::CommentParser::parse_block_comment(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    std::string::const_iterator it = _begin;
    std::stringstream ss;

    svs::ParseResult<std::string> start_syntax_result = parse_string(it, _end, "/*");
    if (!start_syntax_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = start_syntax_result.next();

    while (it != _end)
    {
        svs::ParseResult<std::string> end_syntax_result = parse_string(it, _end, "*/");
        if (end_syntax_result.succeeded())
        {
            it = end_syntax_result.next();
            return svs::ParseResult<std::string>::succeed(ss.str(), it);
        }

        ss << *it;
        ++it;
    }

    return svs::ParseResult<std::string>::fail();
}

/**
 * Mappings from string syntaxes to the corresponding BinaryOperator.
 */
static const std::vector<std::pair<std::string, svs::BinaryOperator>> binary_operator_type_map
{
    // Arithmetic operators
    { "+", svs::BinaryOperator::AdditionBinaryOperator, },
    { "-", svs::BinaryOperator::SubtractionBinaryOperator, },
    { "*", svs::BinaryOperator::MultiplicationBinaryOperator, },
    { "/", svs::BinaryOperator::DivisionBinaryOperator, },
    { "%", svs::BinaryOperator::ModuloBinaryOperator, },
    { "**", svs::BinaryOperator::ExponentiationBinaryOperator, },

    // Relational operators
    { "<", svs::BinaryOperator::LessThanBinaryOperator, },
    { ">", svs::BinaryOperator::GreaterThanBinaryOperator, },
    { "<=", svs::BinaryOperator::LessThanOrEqualToBinaryOperator, },
    { ">=", svs::BinaryOperator::GreaterThanOrEqualToBinaryOperator, },

    // Equality operators
    { "===", svs::BinaryOperator::CaseEqualityBinaryOperator, },
    { "!==", svs::BinaryOperator::CaseInequalityBinaryOperator, },
    { "==", svs::BinaryOperator::LogicalEqualityBinaryOperator, },
    { "!=", svs::BinaryOperator::LogicalInequalityBinaryOperator, },

    // Wildcard equality operators
    { "==?", svs::BinaryOperator::WildcardEqualityBinaryOperator, },
    { "!=?", svs::BinaryOperator::WildcardInequalityBinaryOperator, },

    // Logical operators
    { "&&", svs::BinaryOperator::LogicalAndBinaryOperator, },
    { "||", svs::BinaryOperator::LogicalOrBinaryOperator, },
    { "->", svs::BinaryOperator::LogicalImplicationBinaryOperator, },
    { "<->", svs::BinaryOperator::LogicalEquivalenceBinaryOperator, },
    { "!", svs::BinaryOperator::LogicalNegationBinaryOperator, },

    // Bitwise operators
    { "&", svs::BinaryOperator::BitwiseAndBinaryOperator, },
    { "|", svs::BinaryOperator::BitwiseOrBinaryOperator, },
    { "^", svs::BinaryOperator::BitwiseXorBinaryOperator, },
    { "^~", svs::BinaryOperator::BitwiseXnorBinaryOperator, },
    { "~^", svs::BinaryOperator::BitwiseXnorBinaryOperator, },
    { "~", svs::BinaryOperator::BitwiseNegationBinaryOperator, },

    // Shift operators
    { "<<", svs::BinaryOperator::LogicalLeftShiftBinaryOperator, },
    { ">>", svs::BinaryOperator::LogicalRightShiftBinaryOperator, },
    { "<<<", svs::BinaryOperator::ArithmeticLeftShiftBinaryOperator, },
    { ">>>", svs::BinaryOperator::ArithmeticRightShiftBinaryOperator, },
};

svs::ParseResult<svs::BinaryOperator> svs::BinaryOperatorParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::BinaryOperator>::fail();

    for (const auto& binary_operator_type_mapping : binary_operator_type_map)
    {
        svs::ParseResult<std::string> result = parse_string(
            _begin,
            _end,
            binary_operator_type_mapping.first);
        if (result.succeeded() && result.value().length() > chosen_length)
        {
            chosen_length = result.value().length();
            chosen_result = svs::ParseResult<svs::BinaryOperator>::succeed(
                binary_operator_type_mapping.second,
                result.next());
        }
    }

    return chosen_result;
}

/**
 * Mappings from string syntaxes to the corresponding AssignmentOperator value.
 */
static const std::vector<std::pair<std::string, svs::AssignmentOperator>> assignment_operator_syntax_map
{
    { "=", svs::AssignmentOperator::SimpleAssignment, },
    { "+=", svs::AssignmentOperator::AdditionAssignment, },
    { "-=", svs::AssignmentOperator::SubtractionAssignment, },
    { "*=", svs::AssignmentOperator::MultiplicationAssignment, },
    { "/=", svs::AssignmentOperator::DivisionAssignment, },
    { "%=", svs::AssignmentOperator::ModuloAssignment, },
    { "&=", svs::AssignmentOperator::BitwiseAndAssignment, },
    { "|=", svs::AssignmentOperator::BitwiseOrAssignment, },
    { "^=", svs::AssignmentOperator::BitwiseXorAssignment, },
    { "<<=", svs::AssignmentOperator::LogicalLeftShiftAssignment, },
    { ">>=", svs::AssignmentOperator::LogicalRightShiftAssignment, },
    { "<<<=", svs::AssignmentOperator::ArithmeticLeftShiftAssignment, },
    { ">>>=", svs::AssignmentOperator::ArithmeticRightShiftAssignment, },
};

svs::ParseResult<svs::AssignmentOperator> svs::AssignmentOperatorParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::AssignmentOperator>::fail();

    for (const auto& assignment_operator_syntax_mapping : assignment_operator_syntax_map)
    {
        svs::ParseResult<std::string> result = parse_string(
            _begin,
            _end,
            assignment_operator_syntax_mapping.first);
        if (result.succeeded() && result.value().length() > chosen_length)
        {
            chosen_length = result.value().length();
            chosen_result = svs::ParseResult<svs::AssignmentOperator>::succeed(
                assignment_operator_syntax_mapping.second,
                result.next());
        }
    }

    return chosen_result;
}

/**
 * Mappings from string syntaxes to the corresponding UnaryOperator value.
 */
static const std::vector<std::pair<std::string, svs::UnaryOperator>> unary_operator_syntax_map
{
    { "+", svs::UnaryOperator::PositiveSignUnaryOperator, },
    { "-", svs::UnaryOperator::NegativeSignUnaryOperator, },
    { "!", svs::UnaryOperator::LogicalNegationUnaryOperator, },
    { "~", svs::UnaryOperator::BitwiseNegationUnaryOperator, },
    { "&", svs::UnaryOperator::BitwiseAndUnaryOperator, },
    { "~&", svs::UnaryOperator::BitwiseNandUnaryOperator, },
    { "|", svs::UnaryOperator::BitwiseOrUnaryOperator, },
    { "~|", svs::UnaryOperator::BitwiseNorUnaryOperator, },
    { "^", svs::UnaryOperator::BitwiseXorUnaryOperator, },
    { "~^", svs::UnaryOperator::BitwiseXnorUnaryOperator, },
    { "^~", svs::UnaryOperator::BitwiseXnorUnaryOperator, },
};

svs::ParseResult<svs::UnaryOperator> svs::UnaryOperatorParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::UnaryOperator>::fail();

    for (const auto& unary_operator_syntax_mapping : unary_operator_syntax_map)
    {
        svs::ParseResult<std::string> result = parse_string(
            _begin,
            _end,
            unary_operator_syntax_mapping.first);
        if (result.succeeded() && result.value().length() > chosen_length)
        {
            chosen_length = result.value().length();
            chosen_result = svs::ParseResult<svs::UnaryOperator>::succeed(
                unary_operator_syntax_mapping.second,
                result.next());
        }
    }

    return chosen_result;
}

svs::ParseResult<svs::IncrementOrDecrementOperator> svs::IncrementOrDecrementOperatorParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    svs::ParseResult<std::string> increment_result = parse_string(
        _begin,
        _end,
        "++");
    if (increment_result.succeeded())
    {
        return svs::ParseResult<svs::IncrementOrDecrementOperator>::succeed(
            svs::IncrementOrDecrementOperator::IncrementOperator,
            increment_result.next());
    }

    svs::ParseResult<std::string> decrement_result = parse_string(
        _begin,
        _end,
        "--");
    if (decrement_result.succeeded())
    {
        return svs::ParseResult<svs::IncrementOrDecrementOperator>::succeed(
            svs::IncrementOrDecrementOperator::DecrementOperator,
            decrement_result.next());
    }

    return svs::ParseResult<svs::IncrementOrDecrementOperator>::fail();
}
