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

TEST(SV2017NumberTests, OctalDigitTests)
{
    EXPECT_PARSE_FAILURE<octal_digit>("");

    std::unordered_set<char> characters
        {
            'x', 'X',
            'z', 'Z', '?',
            '0', '1', '2', '3', '4', '5', '6', '7'
        };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<octal_digit>(string, string);
        else
            EXPECT_PARSE_FAILURE<octal_digit>(string);
    }
}

TEST(SV2017NumberTests, BinaryDigitTests)
{
    EXPECT_PARSE_FAILURE<binary_digit>("");

    std::unordered_set<char> characters
        {
            'x', 'X', 'z', 'Z', '?', '0', '1'
        };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<binary_digit>(string, string);
        else
            EXPECT_PARSE_FAILURE<binary_digit>(string);
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

TEST(SV2017NumberTests, OctalBaseTests)
{
    EXPECT_PARSE_FAILURE<octal_base>("");
    EXPECT_PARSE_FAILURE<octal_base>("a");

    EXPECT_PARSE_FAILURE<octal_base>("'");

    EXPECT_PARSE_FAILURE<octal_base>("'");

    EXPECT_PARSE_RESULT<octal_base>("'so", "so");
    EXPECT_PARSE_RESULT<octal_base>("'So", "so");
    EXPECT_PARSE_RESULT<octal_base>("'sO", "so");
    EXPECT_PARSE_RESULT<octal_base>("'SO", "so");

    EXPECT_PARSE_RESULT<octal_base>("'o", "o");
    EXPECT_PARSE_RESULT<octal_base>("'O", "o");
}

TEST(SV2017NumberTests, BinaryBaseTests)
{
    EXPECT_PARSE_FAILURE<binary_base>("");
    EXPECT_PARSE_FAILURE<binary_base>("a");

    EXPECT_PARSE_FAILURE<binary_base>("'");

    EXPECT_PARSE_FAILURE<binary_base>("'");

    EXPECT_PARSE_RESULT<binary_base>("'sb", "sb");
    EXPECT_PARSE_RESULT<binary_base>("'Sb", "sb");
    EXPECT_PARSE_RESULT<binary_base>("'sB", "sb");
    EXPECT_PARSE_RESULT<binary_base>("'SB", "sb");

    EXPECT_PARSE_RESULT<binary_base>("'b", "b");
    EXPECT_PARSE_RESULT<binary_base>("'B", "b");
}

TEST(SV2017NumberTests, DecimalBaseTests)
{
    EXPECT_PARSE_FAILURE<decimal_base>("");
    EXPECT_PARSE_FAILURE<decimal_base>("a");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_RESULT<decimal_base>("'sd", "sd");
    EXPECT_PARSE_RESULT<decimal_base>("'Sd", "sd");
    EXPECT_PARSE_RESULT<decimal_base>("'sD", "sd");
    EXPECT_PARSE_RESULT<decimal_base>("'SD", "sd");

    EXPECT_PARSE_RESULT<decimal_base>("'d", "d");
    EXPECT_PARSE_RESULT<decimal_base>("'D", "d");
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

TEST(SV2017NumberTests, OctalValueTests)
{
    EXPECT_PARSE_FAILURE<octal_value>("");
    EXPECT_PARSE_FAILURE<octal_value>("g");

    EXPECT_PARSE_FAILURE<octal_value>("_012567");

    EXPECT_PARSE_RESULT<octal_value>("12567", "12567");
    EXPECT_PARSE_RESULT<octal_value>("1_25_67", "1_25_67");
    EXPECT_PARSE_RESULT<octal_value>("Z1024X", "Z1024X");
    EXPECT_PARSE_RESULT<octal_value>("Z_10_2_4X", "Z_10_2_4X");
}

TEST(SV2017NumberTests, BinaryValueTests)
{
    EXPECT_PARSE_FAILURE<binary_value>("");
    EXPECT_PARSE_FAILURE<binary_value>("g");

    EXPECT_PARSE_FAILURE<binary_value>("_010110");

    EXPECT_PARSE_RESULT<binary_value>("010110", "010110");
    EXPECT_PARSE_RESULT<binary_value>("01_0_11_0", "01_0_11_0");
    EXPECT_PARSE_RESULT<binary_value>("Z1010X", "Z1010X");
    EXPECT_PARSE_RESULT<binary_value>("Z_10_1_0X", "Z_10_1_0X");
}

TEST(SV2017NumberTests, UnsignedNumberTests)
{
    EXPECT_PARSE_FAILURE<unsigned_number>("");
    EXPECT_PARSE_FAILURE<unsigned_number>("g");

    EXPECT_PARSE_FAILURE<unsigned_number>("_13734189");

    EXPECT_PARSE_RESULT<unsigned_number>("13734189", "13734189");
    EXPECT_PARSE_RESULT<unsigned_number>("13_73_41_8_9", "13_73_41_8_9");
}

TEST(SV2017NumberTests, ExponentTests)
{
    EXPECT_PARSE_FAILURE<exp>("");

    std::unordered_set<char> characters { 'e', 'E' };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<exp>(string, string);
        else
            EXPECT_PARSE_FAILURE<exp>(string);
    }
}

TEST(SV2017NumberTests, FixedPointNumberTests)
{
    EXPECT_PARSE_FAILURE<fixed_point_number>("");
    EXPECT_PARSE_FAILURE<fixed_point_number>("g");

    EXPECT_PARSE_FAILURE<fixed_point_number>("_1373.4189");
    EXPECT_PARSE_FAILURE<fixed_point_number>("1373._4189");

    EXPECT_PARSE_RESULT<fixed_point_number>("1373.4189", "1373.4189");
    EXPECT_PARSE_RESULT<fixed_point_number>("13_73_.41_8_9", "13_73_.41_8_9");
}

TEST(SV2017NumberTests, RealNumberTests)
{
    EXPECT_PARSE_FAILURE<real_number>("");
    EXPECT_PARSE_FAILURE<real_number>("g");

    EXPECT_PARSE_RESULT<real_number>("1373.4189", "1373.4189");
    EXPECT_PARSE_RESULT<real_number>("1373", "1373");

    EXPECT_PARSE_RESULT<real_number>("1373e24", "1373e24");
    EXPECT_PARSE_RESULT<real_number>("1373E24", "1373e24");

    EXPECT_PARSE_RESULT<real_number>("1373e+24", "1373e+24");
    EXPECT_PARSE_RESULT<real_number>("1373E+25", "1373e+25");
    EXPECT_PARSE_RESULT<real_number>("1373e-26", "1373e-26");
    EXPECT_PARSE_RESULT<real_number>("1373E-27", "1373e-27");

    EXPECT_PARSE_RESULT<real_number>("1373.57e+24", "1373.57e+24");
    EXPECT_PARSE_RESULT<real_number>("1373.25E+25", "1373.25e+25");
    EXPECT_PARSE_RESULT<real_number>("1373.78e-26", "1373.78e-26");
    EXPECT_PARSE_RESULT<real_number>("1373.47E-27", "1373.47e-27");
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

TEST(SV2017NumberTests, OctalNumberTests)
{
    EXPECT_PARSE_FAILURE<octal_number>("");
    EXPECT_PARSE_FAILURE<octal_number>("t");

    EXPECT_PARSE_FAILURE<octal_number>("'o8765");
    EXPECT_PARSE_FAILURE<octal_number>("'o 8765");

    EXPECT_PARSE_SUCCESS<octal_number>("'o 12345670");

    EXPECT_PARSE_SUCCESS<octal_number>("'o15");
    EXPECT_PARSE_SUCCESS<octal_number>(" 'o15");
    EXPECT_PARSE_SUCCESS<octal_number>("'o 15");
    EXPECT_PARSE_SUCCESS<octal_number>(" 'o 15");
    EXPECT_PARSE_SUCCESS<octal_number>("6'o15");
    EXPECT_PARSE_SUCCESS<octal_number>("6 'o15");
    EXPECT_PARSE_SUCCESS<octal_number>("6'o 15");
    EXPECT_PARSE_SUCCESS<octal_number>("6 'o 15");

    EXPECT_PARSE_SUCCESS<octal_number>("'o423");
    EXPECT_PARSE_SUCCESS<octal_number>(" 'o423");
    EXPECT_PARSE_SUCCESS<octal_number>("'o 423");
    EXPECT_PARSE_SUCCESS<octal_number>(" 'o 423");
    EXPECT_PARSE_SUCCESS<octal_number>("9'o423");
    EXPECT_PARSE_SUCCESS<octal_number>("9 'o423");
    EXPECT_PARSE_SUCCESS<octal_number>("9'o 423");
    EXPECT_PARSE_SUCCESS<octal_number>("9 'o 423");
}

TEST(SV2017NumberTests, BinaryNumberTests)
{
    EXPECT_PARSE_FAILURE<binary_number>("");
    EXPECT_PARSE_FAILURE<binary_number>("t");

    EXPECT_PARSE_FAILURE<binary_number>("'b2010");
    EXPECT_PARSE_FAILURE<binary_number>("'b 2010");

    EXPECT_PARSE_SUCCESS<binary_number>("'b 1011011010");

    EXPECT_PARSE_SUCCESS<binary_number>("'b10");
    EXPECT_PARSE_SUCCESS<binary_number>(" 'b10");
    EXPECT_PARSE_SUCCESS<binary_number>("'b 10");
    EXPECT_PARSE_SUCCESS<binary_number>(" 'b 10");
    EXPECT_PARSE_SUCCESS<binary_number>("6'b10");
    EXPECT_PARSE_SUCCESS<binary_number>("6 'b10");
    EXPECT_PARSE_SUCCESS<binary_number>("6'b 10");
    EXPECT_PARSE_SUCCESS<binary_number>("6 'b 10");

    EXPECT_PARSE_SUCCESS<binary_number>("'b010");
    EXPECT_PARSE_SUCCESS<binary_number>(" 'b010");
    EXPECT_PARSE_SUCCESS<binary_number>("'b 010");
    EXPECT_PARSE_SUCCESS<binary_number>(" 'b 010");
    EXPECT_PARSE_SUCCESS<binary_number>("9'b010");
    EXPECT_PARSE_SUCCESS<binary_number>("9 'b010");
    EXPECT_PARSE_SUCCESS<binary_number>("9'b 010");
    EXPECT_PARSE_SUCCESS<binary_number>("9 'b 010");
}

