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
 * Mappings from string syntaxes to the corresponding OperatorType value.
 */
static const std::vector<std::pair<std::string, svs::OperatorType>> operator_type_map
{
    // Assignment operators
    { "=", svs::OperatorType::SimpleAssignment, },
    { "+=", svs::OperatorType::AdditionAssignment, },
    { "-=", svs::OperatorType::SubtractionAssignment, },
    { "*=", svs::OperatorType::MultiplicationAssignment, },
    { "/=", svs::OperatorType::DivisionAssignment, },
    { "%=", svs::OperatorType::ModuloAssignment, },
    { "&=", svs::OperatorType::BitwiseAndAssignment, },
    { "|=", svs::OperatorType::BitwiseOrAssignment, },
    { "^=", svs::OperatorType::BitwiseXorAssignment, },
    { "<<=", svs::OperatorType::LogicalLeftShiftAssignment, },
    { ">>=", svs::OperatorType::LogicalRightShiftAssignment, },
    { "<<<=", svs::OperatorType::ArithmeticLeftShiftAssignment, },
    { ">>>=", svs::OperatorType::ArithmeticRightShiftAssignment, },

    // Increment and decrement operators
    { "++", svs::OperatorType::Increment, },
    { "--", svs::OperatorType::Decrement, },

    // Arithmetic operators
    { "+", svs::OperatorType::Addition, },
    { "-", svs::OperatorType::Subtraction, },
    { "*", svs::OperatorType::Multiplication, },
    { "/", svs::OperatorType::Division, },
    { "%", svs::OperatorType::Modulo, },
    { "**", svs::OperatorType::Exponentiation, },

    // Relational operators
    { "<", svs::OperatorType::LessThan, },
    { ">", svs::OperatorType::GreaterThan, },
    { "<=", svs::OperatorType::LessThanOrEqualTo, },
    { ">=", svs::OperatorType::GreaterThanOrEqualTo, },

    // Equality operators
    { "===", svs::OperatorType::CaseEquality, },
    { "!==", svs::OperatorType::CaseInequality, },
    { "==", svs::OperatorType::LogicalEquality, },
    { "!=", svs::OperatorType::LogicalInequality, },

    // Wildcard equality operators
    { "==?", svs::OperatorType::WildcardEquality, },
    { "!=?", svs::OperatorType::WildcardInequality, },

    // Logical operators
    { "&&", svs::OperatorType::LogicalAnd, },
    { "||", svs::OperatorType::LogicalOr, },
    { "->", svs::OperatorType::LogicalImplication, },
    { "<->", svs::OperatorType::LogicalEquivalence, },
    { "!", svs::OperatorType::LogicalNegation, },

    // Bitwise operators
    { "&", svs::OperatorType::BitwiseAnd, },
    { "|", svs::OperatorType::BitwiseOr, },
    { "^", svs::OperatorType::BitwiseXor, },
    { "^~", svs::OperatorType::BitwiseXnor, },
    { "~^", svs::OperatorType::BitwiseXnor, },
    { "~", svs::OperatorType::BitwiseNegation, },

    // Shift operators
    { "<<", svs::OperatorType::LogicalLeftShift, },
    { ">>", svs::OperatorType::LogicalRightShift, },
    { "<<<", svs::OperatorType::ArithmeticLeftShift, },
    { ">>>", svs::OperatorType::ArithmeticRightShift, },

    // Conditional operator
    { "?", svs::OperatorType::ConditionalPredicateOperator, },
    { ":", svs::OperatorType::ConditionalExpressionDelimiter, },

    // Set membership operator
    { "inside", svs::OperatorType::SetMembershipOperator, },
};

svs::ParseResult<svs::OperatorType> svs::OperatorParser::parse(
    const std::string::const_iterator _begin,
    const std::string::const_iterator _end)
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::OperatorType>::fail();

    for (const auto& operator_type_mapping : operator_type_map)
    {
        svs::ParseResult<std::string> result = parse_string(
            _begin,
            _end,
            operator_type_mapping.first);
        if (result.succeeded() && result.value().length() > chosen_length)
        {
            chosen_length = result.value().length();
            chosen_result = svs::ParseResult<svs::OperatorType>::succeed(
                operator_type_mapping.second,
                result.next());
        }
    }

    return chosen_result;
}
