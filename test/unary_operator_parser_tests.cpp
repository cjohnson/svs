#include <gtest/gtest.h>

#include "../src/Parser.h"

TEST(UnaryOperatorParserTests, EmptyString)
{
    svs::UnaryOperatorParser parser;
    std::string string = "";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(UnaryOperatorParserTests, PositiveSignUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "+";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::PositiveSignUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, NegativeSignUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "-";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::NegativeSignUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, LogicalNegationUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "!";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::LogicalNegationUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseNegationUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "~";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseNegationUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseAndUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "&";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseAndUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseNandUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "~&";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseNandUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseOrUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "|";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseOrUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseNorUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "~|";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseNorUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseXorUnaryOperator)
{
    svs::UnaryOperatorParser parser;
    std::string string = "^";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseXorUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseXnorUnaryOperatorTildeFirst)
{
    svs::UnaryOperatorParser parser;
    std::string string = "~^";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseXnorUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(UnaryOperatorParserTests, BitwiseXnorUnaryOperatorCaretFirst)
{
    svs::UnaryOperatorParser parser;
    std::string string = "^~";

    svs::ParseResult<svs::UnaryOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::UnaryOperator::BitwiseXnorUnaryOperator);
    EXPECT_EQ(result.next(), string.end());
}

