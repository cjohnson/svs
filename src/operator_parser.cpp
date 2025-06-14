#include "operator_parser.h"

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
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::BinaryOperator>::fail();

    for (const auto& binary_operator_type_mapping : binary_operator_type_map)
    {
        svs::ParseResult<std::string> result =
            svs::StringParser(binary_operator_type_mapping.first)
                .parse(begin, end);
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
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::AssignmentOperator>::fail();

    for (const auto& assignment_operator_syntax_mapping : assignment_operator_syntax_map)
    {
        svs::ParseResult<std::string> result =
            svs::StringParser(assignment_operator_syntax_mapping.first)
                .parse(begin, end);
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
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    int chosen_length = 0;
    auto chosen_result = svs::ParseResult<svs::UnaryOperator>::fail();

    for (const auto& unary_operator_syntax_mapping : unary_operator_syntax_map)
    {
        svs::ParseResult<std::string> result =
            svs::StringParser(unary_operator_syntax_mapping.first)
                .parse(begin, end);
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
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    svs::ParseResult<std::string> increment_result = svs::StringParser("++").parse(begin, end); 
    if (increment_result.succeeded())
    {
        return svs::ParseResult<svs::IncrementOrDecrementOperator>::succeed(
            svs::IncrementOrDecrementOperator::IncrementOperator,
            increment_result.next());
    }

    svs::ParseResult<std::string> decrement_result = svs::StringParser("--").parse(begin, end);
    if (decrement_result.succeeded())
    {
        return svs::ParseResult<svs::IncrementOrDecrementOperator>::succeed(
            svs::IncrementOrDecrementOperator::DecrementOperator,
            decrement_result.next());
    }

    return svs::ParseResult<svs::IncrementOrDecrementOperator>::fail();
}
