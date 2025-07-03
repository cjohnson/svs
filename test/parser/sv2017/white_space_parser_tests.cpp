#include <lexy/action/match.hpp>
#include <lexy/input/string_input.hpp>

#include <gtest/gtest.h>

#include "../../../src/parser/sv2017_grammar.h"

TEST(WhiteSpaceParserTests, EmptyStringTest)
{
    auto string = lexy::zstring_input("");
    EXPECT_TRUE(lexy::match<sv2017::white_space>(string));
}

TEST(WhiteSpaceParserTests, SpaceTest)
{
    auto string = lexy::zstring_input(" ");
    EXPECT_TRUE(lexy::match<sv2017::white_space>(string));
}

TEST(WhiteSpaceParserTests, TabTest)
{
    auto string = lexy::zstring_input("\t");
    EXPECT_TRUE(lexy::match<sv2017::white_space>(string));
}

TEST(WhiteSpaceParserTests, NewLineTest)
{
    auto string = lexy::zstring_input("\n");
    EXPECT_TRUE(lexy::match<sv2017::white_space>(string));
}

TEST(WhiteSpaceParserTests, NotWhiteSpace)
{
    auto string = lexy::zstring_input("not_whitespace");
    EXPECT_FALSE(lexy::match<sv2017::white_space>(string));
}

