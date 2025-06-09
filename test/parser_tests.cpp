#include <gtest/gtest.h>

#include "../src/Parser.h"

TEST(ParseCharacterSingleMatchTests, EmptyString)
{
    svs::Parser parser;
    std::string empty_string = "";

    svs::ParseResult<char> result = parser.parse_character(
        empty_string.begin(),
        empty_string.end(),
        'a');

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSingleMatchTests, BasicSuccess)
{
    svs::Parser parser;
    std::string string = "a";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        'a');

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.end());
}

TEST(ParseCharacterSingleMatchTests, BasicFailure)
{
    svs::Parser parser;
    std::string string = "b";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        'a');

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSingleMatchTests, ReadsOnlyOne)
{
    svs::Parser parser;
    std::string string = "aaa";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        'a');

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.begin() + 1);
}

TEST(ParseCharacterSingleMatchTests, ReadsNoneFromManyInCaseOfFailure)
{
    svs::Parser parser;
    std::string string = "bbb";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        'a');

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, EmptyString)
{
    svs::Parser parser;
    std::string empty_string = "";

    svs::ParseResult<char> result = parser.parse_character(
        empty_string.begin(),
        empty_string.end(),
        std::unordered_set<char> {'a', 'b', 'c'});

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, BasicSuccess)
{
    svs::Parser parser;
    std::string string = "a";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        std::unordered_set<char> {'a', 'b', 'c'});

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.end());
}

TEST(ParseCharacterSetMatchTests, BasicFailure)
{
    svs::Parser parser;
    std::string string = "d";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        std::unordered_set<char> {'a', 'b', 'c'});

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, ReadsOnlyOne)
{
    svs::Parser parser;
    std::string string = "aaa";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        std::unordered_set<char> {'a', 'b', 'c'});

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.begin() + 1);
}

TEST(ParseCharacterSetMatchTests, ReadsNoneFromManyInCaseOfFailure)
{
    svs::Parser parser;
    std::string string = "ddd";

    svs::ParseResult<char> result = parser.parse_character(
        string.begin(),
        string.end(),
        std::unordered_set<char> {'a', 'b', 'c'});

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, ReadsOnlyInSet)
{
    svs::Parser parser;
    std::string string = "abcd";

    std::unordered_set<char> set{'a', 'b', 'c'};

    std::string::const_iterator begin = string.begin();
    const std::string::const_iterator end = string.end();

    svs::ParseResult<char> result = parser.parse_character(
        begin,
        end,
        set);
    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), begin + 1);

    begin = result.next();

    result = parser.parse_character(
        begin,
        end,
        set);
    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'b');
    EXPECT_EQ(result.next(), begin + 1);

    begin = result.next();

    result = parser.parse_character(
        begin,
        end,
        set);
    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'c');
    EXPECT_EQ(result.next(), begin + 1);

    begin = result.next();

    result = parser.parse_character(
        begin,
        end,
        set);
    EXPECT_FALSE(result.succeeded());
}

TEST(ParseWhitespaceTests, EmptyString)
{
    svs::Parser parser;
    std::string empty_string = "";

    svs::ParseResult<std::string> result = parser.parse_whitespace(
        empty_string.begin(),
        empty_string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseWhitespaceTests, ParsesAllWhitespaceCharacters)
{
    svs::Parser parser;
    std::string string = " \f\n\r\t\vnot_whitespace";

    svs::ParseResult<std::string> result = parser.parse_whitespace(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.begin() + 6);
    EXPECT_EQ(result.value(), std::string(string.begin(), string.begin() + 6));
}

