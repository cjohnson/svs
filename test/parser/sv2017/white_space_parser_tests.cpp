#include <gtest/gtest.h>

#include "../../../src/parser/sv2017/white_space_parser.h"

TEST(WhiteSpaceParserTests, EmptyStringTest)
{
    svs::WhiteSpaceParser parser;
    std::string empty_string = "";

    svs::ParseResult<char> result = parser.parse(
        empty_string.begin(),
        empty_string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), empty_string.end());
    EXPECT_EQ(result.value(), (char)0);
}

TEST(WhiteSpaceParserTests, SpaceTest)
{
    svs::WhiteSpaceParser parser;
    std::string string = " ";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), ' ');
}

TEST(WhiteSpaceParserTests, TabTest)
{
    svs::WhiteSpaceParser parser;
    std::string string = "\t";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), '\t');
}

TEST(WhiteSpaceParserTests, NewLineTest)
{
    svs::WhiteSpaceParser parser;
    std::string string = "\n";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), '\n');
}

TEST(WhiteSpaceParserTests, WhiteSpaceParserSomeWhiteSpaceCharactersParsingTest)
{
    svs::SomeParser<char> parser(std::make_shared<svs::WhiteSpaceParser>());
    std::string string = " \f\n\r\t\vnot_whitespace";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.begin() + 6);

    EXPECT_EQ(result.value(), std::string(string.begin(), string.begin() + 6));
}

