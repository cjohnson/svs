#include <climits>
#include <unordered_set>

#include <gtest/gtest.h>

#include "../../../../src/compiler/sv2017/grammar_number.hpp"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;

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

    EXPECT_PARSE_RESULT<hex_base>("'sh", "sh");
    EXPECT_PARSE_RESULT<hex_base>("'Sh", "sh");
    EXPECT_PARSE_RESULT<hex_base>("'sH", "sh");
    EXPECT_PARSE_RESULT<hex_base>("'SH", "sh");

    EXPECT_PARSE_RESULT<hex_base>("'h", "h");
    EXPECT_PARSE_RESULT<hex_base>("'H", "h");
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

TEST(SV2017NumberTests, NonZeroUnsignedNumberTests)
{
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("g");

    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("0114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("114", "114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4", "1_1_4");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("_1_1_4");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4_", "1_1_4_");
}

TEST(SV2017NumberTests, HexNumberTests)
{
    EXPECT_PARSE_FAILURE<hex_number>("");
    EXPECT_PARSE_FAILURE<hex_number>("t");

    EXPECT_PARSE_FAILURE<hex_number>("'hgdead");
    EXPECT_PARSE_FAILURE<hex_number>("'h gdead");

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

