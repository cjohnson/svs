#include <gtest/gtest.h>

#include "../src/Parser.h"

TEST(IncrementOrDecrementOperatorParserTests, EmptyString)
{
    svs::IncrementOrDecrementOperatorParser parser;
    std::string string = "";

    svs::ParseResult<svs::IncrementOrDecrementOperator> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(IncrementOrDecrementOperatorParserTests, Increment)
{
    svs::IncrementOrDecrementOperatorParser parser;
    std::string string = "++";

    svs::ParseResult<svs::IncrementOrDecrementOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::IncrementOrDecrementOperator::IncrementOperator);
    EXPECT_EQ(result.next(), string.end());
}

TEST(IncrementOrDecrementOperatorParserTests, Decrement)
{
    svs::IncrementOrDecrementOperatorParser parser;
    std::string string = "--";

    svs::ParseResult<svs::IncrementOrDecrementOperator> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), svs::IncrementOrDecrementOperator::DecrementOperator);
    EXPECT_EQ(result.next(), string.end());
}

