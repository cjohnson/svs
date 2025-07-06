#include <climits>
#include <unordered_set>

#include <gtest/gtest.h>

#include "../../../../src/compiler/sv2017/grammar_number.hpp"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;

namespace ast = svs::ast::sv2017;

TEST(SV2017NumberTests, ZOrXTests)
{
    EXPECT_PARSE_FAILURE<z_or_x>("");

    std::unordered_set<char> characters { 'x', 'X', 'z', 'Z' };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<z_or_x>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_or_x>(string);
    }
}

TEST(SV2017NumberTests, UnbasedUnsizedLiteralTests)
{
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("");
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("'");
    EXPECT_PARSE_FAILURE<unbased_unsized_literal>("'a");

    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'0", "0");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'1", "1");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'x", "x");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'X", "X");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'z", "z");
    EXPECT_PARSE_RESULT<unbased_unsized_literal>("'Z", "Z");
}

TEST(SV2017NumberTests, ZDigitTests)
{
    EXPECT_PARSE_FAILURE<z_digit>("");

    std::unordered_set<char> characters { 'z', 'Z', '?' };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);
        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<z_digit>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_digit>(string);
    }
}

TEST(SV2017NumberTests, XDigitTests)
{
    EXPECT_PARSE_FAILURE<x_digit>("");

    std::unordered_set<char> allowed_characters{ 'x', 'X' };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);
        if (allowed_characters.find(c) != allowed_characters.end())
            EXPECT_PARSE_RESULT<x_digit>(string, string);
        else
            EXPECT_PARSE_FAILURE<x_digit>(string);
    }
}

TEST(SV2017NumberTests, HexDigitTests)
{
    EXPECT_PARSE_FAILURE<hex_digit>("");

    std::unordered_set<char> characters
        {
            'x', 'X',
            'z', 'Z', '?',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'a', 'b', 'c', 'd', 'e', 'f',
            'A', 'B', 'C', 'D', 'E', 'F',
        };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<hex_digit>(string, string);
        else
            EXPECT_PARSE_FAILURE<hex_digit>(string);
    }
}

TEST(SV2017NumberTests, HexBaseTests)
{
    EXPECT_PARSE_FAILURE<hex_base>("");
    EXPECT_PARSE_FAILURE<hex_base>("a");

    EXPECT_PARSE_FAILURE<hex_base>("'");

    EXPECT_PARSE_FAILURE<hex_base>("'");

    EXPECT_PARSE_RESULT<hex_base>("'sh", ast::signedness::SIGNED);
    EXPECT_PARSE_RESULT<hex_base>("'Sh", ast::signedness::SIGNED);
    EXPECT_PARSE_RESULT<hex_base>("'sH", ast::signedness::SIGNED);
    EXPECT_PARSE_RESULT<hex_base>("'SH", ast::signedness::SIGNED);

    EXPECT_PARSE_RESULT<hex_base>("'h", ast::signedness::UNSIGNED);
    EXPECT_PARSE_RESULT<hex_base>("'H", ast::signedness::UNSIGNED);
}

TEST(SV2017NumberTests, HexValueTests)
{
    EXPECT_PARSE_FAILURE<hex_value>("");
    EXPECT_PARSE_FAILURE<hex_value>("g");

    EXPECT_PARSE_FAILURE<hex_value>("_01dead");

    EXPECT_PARSE_RESULT<hex_value>("01dead", "01dead");
    EXPECT_PARSE_RESULT<hex_value>("01_de_ad", "01_de_ad");
    EXPECT_PARSE_RESULT<hex_value>("ZbeefX", "ZbeefX");
    EXPECT_PARSE_RESULT<hex_value>("Z_be_ef_X", "Z_be_ef_X");
}

TEST(SV2017NumberTests, HexNumberTests)
{
    EXPECT_PARSE_FAILURE<hex_number>("");
    EXPECT_PARSE_FAILURE<hex_number>("t");

    EXPECT_PARSE_FAILURE<hex_number>("'hgdead");
    EXPECT_PARSE_FAILURE<hex_number>("'h gdead");

    EXPECT_PARSE_SUCCESS<hex_number>("'hdeadbeef9876543210c");
    EXPECT_PARSE_SUCCESS<hex_number>("'h deadbeef9876543210c");

    EXPECT_PARSE_SUCCESS<hex_number>("'h1b");
    EXPECT_PARSE_SUCCESS<hex_number>(" 'h1b");
    EXPECT_PARSE_SUCCESS<hex_number>("'h 1b");
    EXPECT_PARSE_SUCCESS<hex_number>(" 'h 1b");
    EXPECT_PARSE_SUCCESS<hex_number>("8'h1b");
    EXPECT_PARSE_SUCCESS<hex_number>("8 'h1b");
    EXPECT_PARSE_SUCCESS<hex_number>("8'h 1b");
    EXPECT_PARSE_SUCCESS<hex_number>("8 'h 1b");

    EXPECT_PARSE_SUCCESS<hex_number>("'h4ad");
    EXPECT_PARSE_SUCCESS<hex_number>(" 'h4ad");
    EXPECT_PARSE_SUCCESS<hex_number>("'h 4ad");
    EXPECT_PARSE_SUCCESS<hex_number>(" 'h 4ad");
    EXPECT_PARSE_SUCCESS<hex_number>("12'h4ad");
    EXPECT_PARSE_SUCCESS<hex_number>("12 'h4ad");
    EXPECT_PARSE_SUCCESS<hex_number>("12'h 4ad");
    EXPECT_PARSE_SUCCESS<hex_number>("12 'h 4ad");
}

