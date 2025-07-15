#include <climits>
#include <unordered_set>

#include <gtest/gtest.h>
#include <vector>

#include "../../../../src/compiler/sv2017/grammar_number.hpp"
#include "../../../../src/compiler/sv2017/ast_number.h"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;
namespace ast = svs::ast::sv2017;

TEST(SV2017NumberTests, ZOrXTests)
{
    EXPECT_PARSE_FAILURE<z_or_x>("");

    std::unordered_map<char, ast::logic_value_t> valid_mappings
    {
        { 'x', ast::logic_value_t::_X },
        { 'X', ast::logic_value_t::_X },
        { 'z', ast::logic_value_t::_Z },
        { 'Z', ast::logic_value_t::_Z },
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        auto it = valid_mappings.find(c);
        if (it != valid_mappings.end())
            EXPECT_PARSE_RESULT<z_or_x>(string, it->second);
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

    std::unordered_map<char, ast::logic_value_t> valid_mappings
    {
        { 'z', ast::logic_value_t::_Z },
        { 'Z', ast::logic_value_t::_Z },
        { '?', ast::logic_value_t::_Z },
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        auto it = valid_mappings.find(c);
        if (it != valid_mappings.end())
            EXPECT_PARSE_RESULT<z_digit>(string, it->second);
        else
            EXPECT_PARSE_FAILURE<z_digit>(string);
    }
}

TEST(SV2017NumberTests, XDigitTests)
{
    EXPECT_PARSE_FAILURE<x_digit>("");

    std::unordered_map<char, ast::logic_value_t> valid_mappings
    {
        { 'x', ast::logic_value_t::_X },
        { 'X', ast::logic_value_t::_X },
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        auto it = valid_mappings.find(c);
        if (it != valid_mappings.end())
            EXPECT_PARSE_RESULT<x_digit>(string, it->second);
        else
            EXPECT_PARSE_FAILURE<x_digit>(string);
    }
}

static constexpr std::array<ast::logic_value_t, 4> get_hex_bits(char c)
{
    std::array<ast::logic_value_t, 4> result
    {
        ast::logic_value_t::_X,
        ast::logic_value_t::_X,
        ast::logic_value_t::_X,
        ast::logic_value_t::_X,
    };

    c = std::tolower(c);

    switch (c)
    {
    case '0':
    case '2':
    case '4':
    case '6':
    case '8':
    case 'a':
    case 'c':
    case 'e':
        result[0] = ast::logic_value_t::_0;
        break;
    case '1':
    case '3':
    case '5':
    case '7':
    case '9':
    case 'b':
    case 'd':
    case 'f':
        result[0] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '4':
    case '5':
    case '8':
    case '9':
    case 'c':
    case 'd':
        result[1] = ast::logic_value_t::_0;
        break;
    case '2':
    case '3':
    case '6':
    case '7':
    case 'a':
    case 'b':
    case 'e':
    case 'f':
        result[1] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '8':
    case '9':
    case 'a':
    case 'b':
        result[2] = ast::logic_value_t::_0;
        break;
    case '4':
    case '5':
    case '6':
    case '7':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        result[2] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
        result[3] = ast::logic_value_t::_0;
        break;
    case '8':
    case '9':
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        result[3] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case 'x':
        result[0] = ast::logic_value_t::_X;
        result[1] = ast::logic_value_t::_X;
        result[2] = ast::logic_value_t::_X;
        result[3] = ast::logic_value_t::_X;
        break;
    case 'z':
    case '?':
        result[0] = ast::logic_value_t::_Z;
        result[1] = ast::logic_value_t::_Z;
        result[2] = ast::logic_value_t::_Z;
        result[3] = ast::logic_value_t::_Z;
        break;
    }

    return result;
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

        std::array<ast::logic_value_t, 4> bits = get_hex_bits(c);
        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<hex_digit>(string, bits);
        else
            EXPECT_PARSE_FAILURE<hex_digit>(string);
    }
}

static constexpr std::array<ast::logic_value_t, 3> get_octal_bits(char c)
{
    std::array<ast::logic_value_t, 3> result
    {
        ast::logic_value_t::_X,
        ast::logic_value_t::_X,
        ast::logic_value_t::_X,
    };

    c = std::tolower(c);

    switch (c)
    {
    case '0':
    case '2':
    case '4':
    case '6':
        result[0] = ast::logic_value_t::_0;
        break;
    case '1':
    case '3':
    case '5':
    case '7':
        result[0] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '4':
    case '5':
        result[1] = ast::logic_value_t::_0;
        break;
    case '2':
    case '3':
    case '6':
    case '7':
        result[1] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
        result[2] = ast::logic_value_t::_0;
        break;
    case '4':
    case '5':
    case '6':
    case '7':
        result[2] = ast::logic_value_t::_1;
        break;
    }

    switch (c)
    {
    case 'x':
        result[0] = ast::logic_value_t::_X;
        result[1] = ast::logic_value_t::_X;
        result[2] = ast::logic_value_t::_X;
        break;
    case 'z':
    case '?':
        result[0] = ast::logic_value_t::_Z;
        result[1] = ast::logic_value_t::_Z;
        result[2] = ast::logic_value_t::_Z;
        break;
    }

    return result;
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
            EXPECT_PARSE_RESULT<octal_digit>(string, get_octal_bits(c));
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

    EXPECT_PARSE_RESULT<hex_base>("'sh", true);
    EXPECT_PARSE_RESULT<hex_base>("'Sh", true);
    EXPECT_PARSE_RESULT<hex_base>("'sH", true);
    EXPECT_PARSE_RESULT<hex_base>("'SH", true);

    EXPECT_PARSE_RESULT<hex_base>("'h", false);
    EXPECT_PARSE_RESULT<hex_base>("'H", false);
}

TEST(SV2017NumberTests, OctalBaseTests)
{
    EXPECT_PARSE_FAILURE<octal_base>("");
    EXPECT_PARSE_FAILURE<octal_base>("a");

    EXPECT_PARSE_FAILURE<octal_base>("'");

    EXPECT_PARSE_RESULT<octal_base>("'so", true);
    EXPECT_PARSE_RESULT<octal_base>("'So", true);
    EXPECT_PARSE_RESULT<octal_base>("'sO", true);
    EXPECT_PARSE_RESULT<octal_base>("'SO", true);

    EXPECT_PARSE_RESULT<octal_base>("'o", false);
    EXPECT_PARSE_RESULT<octal_base>("'O", false);
}

TEST(SV2017NumberTests, BinaryBaseTests)
{
    EXPECT_PARSE_FAILURE<binary_base>("");
    EXPECT_PARSE_FAILURE<binary_base>("a");

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

static constexpr std::vector<ast::logic_value_t> get_hex_bits(
    std::string hex_string)
{
    std::vector<ast::logic_value_t> result;

    for (const char& c : hex_string)
    {
        std::array<ast::logic_value_t, 4> nibble = get_hex_bits(c);
        for (const ast::logic_value_t& bit : nibble)
        {
            result.push_back(bit);
        }
    }

    return result;
}

TEST(SV2017NumberTests, HexValueTests)
{
    EXPECT_PARSE_FAILURE<hex_value>("");
    EXPECT_PARSE_FAILURE<hex_value>("g");

    EXPECT_PARSE_FAILURE<hex_value>("_01dead");

    EXPECT_PARSE_RESULT<hex_value>("01dead", get_hex_bits("01dead"));
    EXPECT_PARSE_RESULT<hex_value>("01_de_ad", get_hex_bits("01dead"));
    EXPECT_PARSE_RESULT<hex_value>("ZbeefX", get_hex_bits("ZbeefX"));
    EXPECT_PARSE_RESULT<hex_value>("Z_be_ef_X", get_hex_bits("ZbeefX"));
}

static constexpr std::vector<ast::logic_value_t> get_octal_bits(
    std::string octal_string)
{
    std::vector<ast::logic_value_t> result;

    for (const char& c : octal_string)
    {
        std::array<ast::logic_value_t, 3> trio = get_octal_bits(c);
        for (const ast::logic_value_t& bit : trio)
        {
            result.push_back(bit);
        }
    }

    return result;
}

TEST(SV2017NumberTests, OctalValueTests)
{
    EXPECT_PARSE_FAILURE<octal_value>("");
    EXPECT_PARSE_FAILURE<octal_value>("g");

    EXPECT_PARSE_FAILURE<octal_value>("_012567");

    EXPECT_PARSE_RESULT<octal_value>("12567", get_octal_bits("12567"));
    EXPECT_PARSE_RESULT<octal_value>("1_25_67", get_octal_bits("12567"));
    EXPECT_PARSE_RESULT<octal_value>("Z1024X", get_octal_bits("Z1024X"));
    EXPECT_PARSE_RESULT<octal_value>("Z_10_2_4X", get_octal_bits("Z1024X"));
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

template<typename TProduction>
void test_real_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("g");

    EXPECT_PARSE_SUCCESS<TProduction>("1373.4189");
    EXPECT_PARSE_SUCCESS<TProduction>("1373");

    EXPECT_PARSE_SUCCESS<TProduction>("1373e24");
    EXPECT_PARSE_SUCCESS<TProduction>("1373E24");

    EXPECT_PARSE_SUCCESS<TProduction>("1373e+24");
    EXPECT_PARSE_SUCCESS<TProduction>("1373E+25");
    EXPECT_PARSE_SUCCESS<TProduction>("1373e-26");
    EXPECT_PARSE_SUCCESS<TProduction>("1373E-27");

    EXPECT_PARSE_SUCCESS<TProduction>("1373.57e+24");
    EXPECT_PARSE_SUCCESS<TProduction>("1373.25E+25");
    EXPECT_PARSE_SUCCESS<TProduction>("1373.78e-26");
    EXPECT_PARSE_SUCCESS<TProduction>("1373.47E-27");
}

TEST(SV2017NumberTests, RealNumberTests)
{
    test_real_number_parsing<real_number>();
}

TEST(SV2017NumberTests, NonZeroUnsignedNumberTests)
{
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("g");

    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("0114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("114", 114);
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4", 114);
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("_1_1_4");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4_", 114);
}

template<typename TProduction>
void test_hex_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'hgdead");
    EXPECT_PARSE_FAILURE<TProduction>("'h gdead");

    EXPECT_PARSE_SUCCESS<TProduction>("'h deadbeef9876543210c");

    EXPECT_PARSE_SUCCESS<TProduction>("'h1b");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'h1b");
    EXPECT_PARSE_SUCCESS<TProduction>("'h 1b");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'h 1b");
    EXPECT_PARSE_SUCCESS<TProduction>("8'h1b");
    EXPECT_PARSE_SUCCESS<TProduction>("8 'h1b");
    EXPECT_PARSE_SUCCESS<TProduction>("8'h 1b");
    EXPECT_PARSE_SUCCESS<TProduction>("8 'h 1b");

    EXPECT_PARSE_SUCCESS<TProduction>("'h4ad");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'h4ad");
    EXPECT_PARSE_SUCCESS<TProduction>("'h 4ad");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'h 4ad");
    EXPECT_PARSE_SUCCESS<TProduction>("12'h4ad");
    EXPECT_PARSE_SUCCESS<TProduction>("12 'h4ad");
    EXPECT_PARSE_SUCCESS<TProduction>("12'h 4ad");
    EXPECT_PARSE_SUCCESS<TProduction>("12 'h 4ad");
}

TEST(SV2017NumberTests, HexNumberTests)
{
    EXPECT_PARSE_FAILURE<hex_number>("");
    EXPECT_PARSE_FAILURE<hex_number>("t");

    EXPECT_PARSE_FAILURE<hex_number>("'hgdead");
    EXPECT_PARSE_FAILURE<hex_number>("'h gdead");

    EXPECT_PARSE_RESULT<hex_number>(
        "'h deadbeef9876543210c",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("deadbeef9876543210c"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "'h1b",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        " 'h1b",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "'h 1b",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        " 'h 1b",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "8'h1b",
        ast::integer_literal_constant_t
        { 8, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "8 'h1b",
        ast::integer_literal_constant_t
        { 8, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "8'h 1b",
        ast::integer_literal_constant_t
        { 8, false, get_hex_bits("1b"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "8 'h 1b",
        ast::integer_literal_constant_t
        { 8, false, get_hex_bits("1b"), });

    EXPECT_PARSE_RESULT<hex_number>(
        "'h4ad",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        " 'h4ad",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "'h 4ad",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        " 'h 4ad",
        ast::integer_literal_constant_t
        { std::nullopt, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "12'h4ad",
        ast::integer_literal_constant_t
        { 12, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "12 'h4ad",
        ast::integer_literal_constant_t
        { 12, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "12'h 4ad",
        ast::integer_literal_constant_t
        { 12, false, get_hex_bits("4ad"), });
    EXPECT_PARSE_RESULT<hex_number>(
        "12 'h 4ad",
        ast::integer_literal_constant_t
        { 12, false, get_hex_bits("4ad"), });
}

template<typename TProduction>
void test_octal_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'o8765");
    EXPECT_PARSE_FAILURE<TProduction>("'o 8765");

    EXPECT_PARSE_SUCCESS<TProduction>("'o 12345670");

    EXPECT_PARSE_SUCCESS<TProduction>("'o15");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'o15");
    EXPECT_PARSE_SUCCESS<TProduction>("'o 15");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'o 15");
    EXPECT_PARSE_SUCCESS<TProduction>("6'o15");
    EXPECT_PARSE_SUCCESS<TProduction>("6 'o15");
    EXPECT_PARSE_SUCCESS<TProduction>("6'o 15");
    EXPECT_PARSE_SUCCESS<TProduction>("6 'o 15");

    EXPECT_PARSE_SUCCESS<TProduction>("'o423");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'o423");
    EXPECT_PARSE_SUCCESS<TProduction>("'o 423");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'o 423");
    EXPECT_PARSE_SUCCESS<TProduction>("9'o423");
    EXPECT_PARSE_SUCCESS<TProduction>("9 'o423");
    EXPECT_PARSE_SUCCESS<TProduction>("9'o 423");
    EXPECT_PARSE_SUCCESS<TProduction>("9 'o 423");
}

TEST(SV2017NumberTests, OctalNumberTests)
{
    EXPECT_PARSE_FAILURE<octal_number>("");
    EXPECT_PARSE_FAILURE<octal_number>("t");

    EXPECT_PARSE_FAILURE<octal_number>("'o8765");
    EXPECT_PARSE_FAILURE<octal_number>("'o 8765");

    EXPECT_PARSE_RESULT<octal_number>(
        "'o 12345670",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("12345670"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "'o15",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        " 'o15",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "'o 15",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        " 'o 15",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "6'o15",
        ast::integer_literal_constant_t{ 6, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "6 'o15",
        ast::integer_literal_constant_t{ 6, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "6'o 15",
        ast::integer_literal_constant_t{ 6, false, get_octal_bits("15"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "6 'o 15",
        ast::integer_literal_constant_t{ 6, false, get_octal_bits("15"), });

    EXPECT_PARSE_RESULT<octal_number>(
        "'o423",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        " 'o423",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "'o 423",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        " 'o 423",
        ast::integer_literal_constant_t{ std::nullopt, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "9'o423",
        ast::integer_literal_constant_t{ 9, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "9 'o423",
        ast::integer_literal_constant_t{ 9, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "9'o 423",
        ast::integer_literal_constant_t{ 9, false, get_octal_bits("423"), });
    EXPECT_PARSE_RESULT<octal_number>(
        "9 'o 423",
        ast::integer_literal_constant_t{ 9, false, get_octal_bits("423"), });
}

template<typename TProduction>
void test_binary_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'b2010");
    EXPECT_PARSE_FAILURE<TProduction>("'b 2010");

    EXPECT_PARSE_SUCCESS<TProduction>("'b 1011011010");

    EXPECT_PARSE_SUCCESS<TProduction>("'b10");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'b10");
    EXPECT_PARSE_SUCCESS<TProduction>("'b 10");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'b 10");
    EXPECT_PARSE_SUCCESS<TProduction>("6'b10");
    EXPECT_PARSE_SUCCESS<TProduction>("6 'b10");
    EXPECT_PARSE_SUCCESS<TProduction>("6'b 10");
    EXPECT_PARSE_SUCCESS<TProduction>("6 'b 10");

    EXPECT_PARSE_SUCCESS<TProduction>("'b010");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'b010");
    EXPECT_PARSE_SUCCESS<TProduction>("'b 010");
    EXPECT_PARSE_SUCCESS<TProduction>(" 'b 010");
    EXPECT_PARSE_SUCCESS<TProduction>("9'b010");
    EXPECT_PARSE_SUCCESS<TProduction>("9 'b010");
    EXPECT_PARSE_SUCCESS<TProduction>("9'b 010");
    EXPECT_PARSE_SUCCESS<TProduction>("9 'b 010");
}

TEST(SV2017NumberTests, BinaryNumberTests)
{
    test_binary_number_parsing<binary_number>();
}

template<typename TProduction>
void test_decimal_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_SUCCESS<TProduction>("0");
    EXPECT_PARSE_SUCCESS<TProduction>("123");

    EXPECT_PARSE_SUCCESS<TProduction>("'d123");
    EXPECT_PARSE_SUCCESS<TProduction>("'d 123");

    EXPECT_PARSE_SUCCESS<TProduction>("20'd123");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd123");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd 123");

    EXPECT_PARSE_SUCCESS<TProduction>("20'dx");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dX");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dx");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dX");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd x");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd X");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dx_");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dX_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dx_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dX_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd x_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd X_");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dx__");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dX__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dx__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dX__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd x__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd X__");

    EXPECT_PARSE_SUCCESS<TProduction>("20'dz");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dZ");
    EXPECT_PARSE_SUCCESS<TProduction>("20'd?");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dz");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dZ");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd?");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd z");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd Z");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd ?");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dz_");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dZ_");
    EXPECT_PARSE_SUCCESS<TProduction>("20'd?_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dz_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dZ_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd?_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd z_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd Z_");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd ?_");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dz__");
    EXPECT_PARSE_SUCCESS<TProduction>("20'dZ__");
    EXPECT_PARSE_SUCCESS<TProduction>("20'd?__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dz__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'dZ__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd?__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd z__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd Z__");
    EXPECT_PARSE_SUCCESS<TProduction>("20 'd ?__");
}

TEST(SV2017NumberTests, DecimalNumberTests)
{
    test_decimal_number_parsing<decimal_number>();
}

template<typename TProduction>
void test_integral_number_parsing()
{
    test_decimal_number_parsing<TProduction>();
    test_octal_number_parsing<TProduction>();
    test_binary_number_parsing<TProduction>();
    test_hex_number_parsing<TProduction>();
}

TEST(SV2017NumberTests, IntegralNumberTests)
{
    test_integral_number_parsing<integral_number>();
}

TEST(SV2017NumberTests, NumberTests)
{
    test_integral_number_parsing<number>();
    test_real_number_parsing<number>();
}

