#include <gtest/gtest.h>

#include "../../../src/parser/sv2017/string_literal_parser.h"

TEST(StringLiteralParserTests, EmptyString)
{
    svs::StringLiteralParser parser;
    std::string string = "";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(StringLiteralParserTests, MinimalForm)
{
    svs::StringLiteralParser parser;
    std::string string = "\"\"";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "");
    EXPECT_EQ(result.next(), string.end());
}

TEST(StringLiteralParserTests, SpecTest1)
{
    svs::StringLiteralParser parser;
    std::string string = "\"Humpty Dumpty sat on a wall. \\\nHumpty Dumpty had a great fall.\"";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "Humpty Dumpty sat on a wall. Humpty Dumpty had a great fall.");
    EXPECT_EQ(result.next(), string.end());
}

