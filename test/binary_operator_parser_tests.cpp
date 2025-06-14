#include <gtest/gtest.h>

#include "../src/operator_parser.h"

TEST(BinaryOperatorParserTests, EmptyString)
{
    svs::BinaryOperatorParser parser;
    std::string string = "";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(BinaryOperatorParserTests, Addition)
{
    svs::BinaryOperatorParser parser;
    std::string string = "+";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::AdditionBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, Subtraction)
{
    svs::BinaryOperatorParser parser;
    std::string string = "-";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::SubtractionBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, Multiplication)
{
    svs::BinaryOperatorParser parser;
    std::string string = "*";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::MultiplicationBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, Division)
{
    svs::BinaryOperatorParser parser;
    std::string string = "/";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::DivisionBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, Modulo)
{
    svs::BinaryOperatorParser parser;
    std::string string = "%";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::ModuloBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, Exponentiation)
{
    svs::BinaryOperatorParser parser;
    std::string string = "**";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::ExponentiationBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LessThan)
{
    svs::BinaryOperatorParser parser;
    std::string string = "<";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LessThanBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, GreaterThan)
{
    svs::BinaryOperatorParser parser;
    std::string string = ">";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::GreaterThanBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LessThanOrEqualTo)
{
    svs::BinaryOperatorParser parser;
    std::string string = "<=";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LessThanOrEqualToBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, GreaterThanOrEqualTo)
{
    svs::BinaryOperatorParser parser;
    std::string string = ">=";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::GreaterThanOrEqualToBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, CaseEquality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "===";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::CaseEqualityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, CaseInequality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "!==";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::CaseInequalityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalEquality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "==";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalEqualityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalInequality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "!=";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalInequalityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, WildcardEquality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "==?";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::WildcardEqualityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, WildcardInequality)
{
    svs::BinaryOperatorParser parser;
    std::string string = "!=?";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::WildcardInequalityBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalAnd)
{
    svs::BinaryOperatorParser parser;
    std::string string = "&&";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalAndBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalOr)
{
    svs::BinaryOperatorParser parser;
    std::string string = "||";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalOrBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalImplication)
{
    svs::BinaryOperatorParser parser;
    std::string string = "->";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalImplicationBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalEquivalence)
{
    svs::BinaryOperatorParser parser;
    std::string string = "<->";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalEquivalenceBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalNegation)
{
    svs::BinaryOperatorParser parser;
    std::string string = "!";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalNegationBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseAnd)
{
    svs::BinaryOperatorParser parser;
    std::string string = "&";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseAndBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseOr)
{
    svs::BinaryOperatorParser parser;
    std::string string = "|";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseOrBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseXor)
{
    svs::BinaryOperatorParser parser;
    std::string string = "^";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseXorBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseXnorCaretFirst)
{
    svs::BinaryOperatorParser parser;
    std::string string = "^~";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseXnorBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseXnorTildeFirst)
{
    svs::BinaryOperatorParser parser;
    std::string string = "~^";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseXnorBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, BitwiseNegation)
{
    svs::BinaryOperatorParser parser;
    std::string string = "~";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::BitwiseNegationBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalLeftShift)
{
    svs::BinaryOperatorParser parser;
    std::string string = "<<";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalLeftShiftBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, LogicalRightShift)
{
    svs::BinaryOperatorParser parser;
    std::string string = ">>";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::LogicalRightShiftBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, ArithmeticLeftShift)
{
    svs::BinaryOperatorParser parser;
    std::string string = "<<<";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::ArithmeticLeftShiftBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(BinaryOperatorParserTests, ArithmeticRightShift)
{
    svs::BinaryOperatorParser parser;
    std::string string = ">>>";

    svs::ParseResult<svs::BinaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::BinaryOperator::ArithmeticRightShiftBinaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

