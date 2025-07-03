#include <gtest/gtest.h>
#include <iostream>

#include "../../src/parser/parser.h"

TEST(ParseCharacterSingleMatchTests, EmptyString)
{
    std::string string = "";
    auto parser = svs::parser::char_<'a'>;

    auto result = parser.parse(string.begin(), string.end());

    EXPECT_FALSE(result);
}

TEST(ParseCharacterSingleMatchTests, BasicSuccess)
{
    std::string string = "a";
    auto parser = svs::parser::char_<'a'>;

    auto result = parser.parse(string.begin(), string.end());

    ASSERT_TRUE(result);
    EXPECT_EQ(result->value, 'a');
    EXPECT_EQ(result->next, string.end());
}

TEST(ParseCharacterSingleMatchTests, BasicFailure)
{
    std::string string = "b";
    auto parser = svs::parser::char_<'a'>;

    auto result = parser.parse(string.begin(), string.end());

    EXPECT_FALSE(result);
}

TEST(ParseCharacterSingleMatchTests, ReadsOnlyOne)
{
    std::string string = "aaa";
    auto parser = svs::parser::char_<'a'>;

    auto result = parser.parse(string.begin(), string.end());

    ASSERT_TRUE(result);
    EXPECT_EQ(result->value, 'a');
    EXPECT_EQ(result->next, string.begin() + 1);
}

TEST(ParseCharacterSingleMatchTests, ReadsNoneFromManyInCaseOfFailure)
{
    std::string string = "bbb";
    auto parser = svs::parser::char_<'a'>;

    auto result = parser.parse(string.begin(), string.end());

    EXPECT_FALSE(result);
}

TEST(ParseCharacterSetMatchTests, EmptyString)
{
    std::string string = "";
    auto parser = svs::parser::char_<'a'> | svs::parser::char_<'b'> | svs::parser::char_<'c'>;
    std::cout << parser->to_string() << '\n';

    auto result = parser->parse(string.begin(), string.end());

    EXPECT_FALSE(result);
}

TEST(ParseCharacterSetMatchTests, BasicSuccess)
{
    std::string string = "a";
    auto parser = svs::parser::char_<'a'> | svs::parser::char_<'b'> | svs::parser::char_<'c'>;

    auto result = parser->parse(string.begin(), string.end());

    ASSERT_TRUE(result);
    EXPECT_EQ(result->value, 'a');
    EXPECT_EQ(result->next, string.end());
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
    svs::SomeParser<char> parser(
        std::make_shared<svs::CharacterParser>(
            std::unordered_set<char>{'a', 'b', 'c'}));
    std::string string = "abcd";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "abc");
    EXPECT_EQ(result.next(), string.begin() + 3);
}

