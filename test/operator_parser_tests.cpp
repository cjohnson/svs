#include <gtest/gtest.h>

#include "../src/Parser.h"

TEST(OperatorParserTests, EmptyString)
{
    svs::OperatorParser parser;
    std::string string = "";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(OperatorParserTests, SimpleAssignment)
{
    svs::OperatorParser parser;
    std::string string = "=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::SimpleAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, AdditionAssignment)
{
    svs::OperatorParser parser;
    std::string string = "+=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::AdditionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, SubtractionAssignment)
{
    svs::OperatorParser parser;
    std::string string = "-=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::SubtractionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, MultiplicationAssignment)
{
    svs::OperatorParser parser;
    std::string string = "*=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::MultiplicationAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, DivisionAssignment)
{
    svs::OperatorParser parser;
    std::string string = "/=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::DivisionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ModuloAssignment)
{
    svs::OperatorParser parser;
    std::string string = "%=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ModuloAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseAndAssignment)
{
    svs::OperatorParser parser;
    std::string string = "&=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseAndAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseOrAssignment)
{
    svs::OperatorParser parser;
    std::string string = "|=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseOrAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseXorAssignment)
{
    svs::OperatorParser parser;
    std::string string = "^=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseXorAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalLeftShiftAssignment)
{
    svs::OperatorParser parser;
    std::string string = "<<=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalLeftShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalRightShiftAssignment)
{
    svs::OperatorParser parser;
    std::string string = ">>=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalRightShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ArithmeticLeftShiftAssignment)
{
    svs::OperatorParser parser;
    std::string string = "<<<=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ArithmeticLeftShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ArithmeticRightShiftAssignment)
{
    svs::OperatorParser parser;
    std::string string = ">>>=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ArithmeticRightShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Increment)
{
    svs::OperatorParser parser;
    std::string string = "++";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Increment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Decrement)
{
    svs::OperatorParser parser;
    std::string string = "--";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Decrement);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Addition)
{
    svs::OperatorParser parser;
    std::string string = "+";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Addition);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Subtraction)
{
    svs::OperatorParser parser;
    std::string string = "-";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Subtraction);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Multiplication)
{
    svs::OperatorParser parser;
    std::string string = "*";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Multiplication);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Division)
{
    svs::OperatorParser parser;
    std::string string = "/";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Division);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Modulo)
{
    svs::OperatorParser parser;
    std::string string = "%";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Modulo);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, Exponentiation)
{
    svs::OperatorParser parser;
    std::string string = "**";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::Exponentiation);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LessThan)
{
    svs::OperatorParser parser;
    std::string string = "<";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LessThan);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, GreaterThan)
{
    svs::OperatorParser parser;
    std::string string = ">";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::GreaterThan);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LessThanOrEqualTo)
{
    svs::OperatorParser parser;
    std::string string = "<=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LessThanOrEqualTo);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, GreaterThanOrEqualTo)
{
    svs::OperatorParser parser;
    std::string string = ">=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::GreaterThanOrEqualTo);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, CaseEquality)
{
    svs::OperatorParser parser;
    std::string string = "===";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::CaseEquality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, CaseInequality)
{
    svs::OperatorParser parser;
    std::string string = "!==";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::CaseInequality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalEquality)
{
    svs::OperatorParser parser;
    std::string string = "==";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalEquality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalInequality)
{
    svs::OperatorParser parser;
    std::string string = "!=";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalInequality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, WildcardEquality)
{
    svs::OperatorParser parser;
    std::string string = "==?";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::WildcardEquality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, WildcardInequality)
{
    svs::OperatorParser parser;
    std::string string = "!=?";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::WildcardInequality);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalAnd)
{
    svs::OperatorParser parser;
    std::string string = "&&";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalAnd);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalOr)
{
    svs::OperatorParser parser;
    std::string string = "||";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalOr);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalImplication)
{
    svs::OperatorParser parser;
    std::string string = "->";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalImplication);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalEquivalence)
{
    svs::OperatorParser parser;
    std::string string = "<->";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalEquivalence);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalNegation)
{
    svs::OperatorParser parser;
    std::string string = "!";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalNegation);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseAnd)
{
    svs::OperatorParser parser;
    std::string string = "&";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseAnd);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseOr)
{
    svs::OperatorParser parser;
    std::string string = "|";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseOr);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseXor)
{
    svs::OperatorParser parser;
    std::string string = "^";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseXor);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseXnorCaretFirst)
{
    svs::OperatorParser parser;
    std::string string = "^~";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseXnor);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseXnorTildeFirst)
{
    svs::OperatorParser parser;
    std::string string = "~^";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseXnor);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, BitwiseNegation)
{
    svs::OperatorParser parser;
    std::string string = "~";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::BitwiseNegation);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalLeftShift)
{
    svs::OperatorParser parser;
    std::string string = "<<";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalLeftShift);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, LogicalRightShift)
{
    svs::OperatorParser parser;
    std::string string = ">>";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::LogicalRightShift);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ArithmeticLeftShift)
{
    svs::OperatorParser parser;
    std::string string = "<<<";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ArithmeticLeftShift);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ArithmeticRightShift)
{
    svs::OperatorParser parser;
    std::string string = ">>>";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ArithmeticRightShift);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ConditionalPredicateOperator)
{
    svs::OperatorParser parser;
    std::string string = "?";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ConditionalPredicateOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, ConditionalExpressionDelimiter)
{
    svs::OperatorParser parser;
    std::string string = ":";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::ConditionalExpressionDelimiter);
    EXPECT_EQ(result.next(), string.end());
}

TEST(OperatorParserTests, SetMembershipOperator)
{
    svs::OperatorParser parser;
    std::string string = "inside";

    svs::ParseResult<svs::OperatorType> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::OperatorType::SetMembershipOperator);
    EXPECT_EQ(result.next(), string.end());
}

