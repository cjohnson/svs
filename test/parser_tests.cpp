#include <gtest/gtest.h>

#include "../src/parser.h"

TEST(ParseCharacterSingleMatchTests, EmptyString)
{
    svs::CharacterParser parser('a');
    std::string empty_string = "";

    svs::ParseResult<char> result = parser.parse(
        empty_string.begin(),
        empty_string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSingleMatchTests, BasicSuccess)
{
    svs::CharacterParser parser('a');
    std::string string = "a";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.end());
}

TEST(ParseCharacterSingleMatchTests, BasicFailure)
{
    svs::CharacterParser parser('a');
    std::string string = "b";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSingleMatchTests, ReadsOnlyOne)
{
    svs::CharacterParser parser('a');
    std::string string = "aaa";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.begin() + 1);
}

TEST(ParseCharacterSingleMatchTests, ReadsNoneFromManyInCaseOfFailure)
{
    svs::CharacterParser parser('a');
    std::string string = "bbb";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, EmptyString)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string empty_string = "";

    svs::ParseResult<char> result = parser.parse(
        empty_string.begin(),
        empty_string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, BasicSuccess)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string string = "a";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.end());
}

TEST(ParseCharacterSetMatchTests, BasicFailure)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string string = "d";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, ReadsOnlyOne)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string string = "aaa";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), 'a');
    EXPECT_EQ(result.next(), string.begin() + 1);
}

TEST(ParseCharacterSetMatchTests, ReadsNoneFromManyInCaseOfFailure)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string string = "ddd";

    svs::ParseResult<char> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseCharacterSetMatchTests, ReadsOnlyInSet)
{
    svs::CharacterParser parser({'a', 'b', 'c'});
    std::string string = "abcd";

    svs::ParseResult<std::string> result = parser.parse_some(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "abc");
    EXPECT_EQ(result.next(), string.begin() + 3);
}

TEST(ParseWhitespaceTests, EmptyString)
{
    svs::WhitespaceParser parser;
    std::string empty_string = "";

    svs::ParseResult<std::string> result = parser.parse_some(
        empty_string.begin(),
        empty_string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(ParseWhitespaceTests, ParsesAllWhitespaceCharacters)
{
    svs::WhitespaceParser parser;
    std::string string = " \f\n\r\t\vnot_whitespace";

    svs::ParseResult<std::string> result = parser.parse_some(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.begin() + 6);

    EXPECT_EQ(result.value(), std::string(string.begin(), string.begin() + 6));
}

