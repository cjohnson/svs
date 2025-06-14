#include <gtest/gtest.h>

#include "../src/operator_parser.h"

TEST(AssignmentOperatorParserTests, EmptyString)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(AssignmentOperatorParserTests, SimpleAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::SimpleAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, AdditionAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "+=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::AdditionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, SubtractionAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "-=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::SubtractionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, MultiplicationAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "*=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::MultiplicationAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, DivisionAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "/=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::DivisionAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, ModuloAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "%=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::ModuloAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, BitwiseAndAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "&=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::BitwiseAndAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, BitwiseOrAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "|=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::BitwiseOrAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, BitwiseXorAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "^=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::BitwiseXorAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, LogicalLeftShiftAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "<<=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::LogicalLeftShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, LogicalRightShiftAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = ">>=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::LogicalRightShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, ArithmeticLeftShiftAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = "<<<=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::ArithmeticLeftShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}

TEST(AssignmentOperatorParserTests, ArithmeticRightShiftAssignment)
{
    svs::AssignmentOperatorParser parser;
    std::string string = ">>>=";

    svs::ParseResult<svs::AssignmentOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::AssignmentOperator::ArithmeticRightShiftAssignment);
    EXPECT_EQ(result.next(), string.end());
}
