#include <climits>
#include <unordered_set>

#include <gtest/gtest.h>

#include "../../../../src/compiler/sv2017/grammar_number.hpp"
#include "../../../../src/compiler/sv2017/ast_number.h"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;
namespace ast = svs::ast::sv2017;

struct z_or_x_production
{
    static constexpr auto rule = dsl::capture(z_or_x);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ZOrXTests)
{
    EXPECT_PARSE_FAILURE<z_or_x_production>("");

    std::unordered_set<char> valid_characters{ 'z', 'Z', 'x', 'X' };
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (valid_characters.find(c) != valid_characters.end())
            EXPECT_PARSE_RESULT<z_or_x_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_or_x_production>(string);
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

struct z_digit_production
{
    static constexpr auto rule = dsl::capture(z_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ZDigitTests)
{
    EXPECT_PARSE_FAILURE<z_digit_production>("");

    std::unordered_set<char> valid_characters{ 'z', 'Z', '?' };
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (valid_characters.find(c) != valid_characters.end())
            EXPECT_PARSE_RESULT<z_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<z_digit_production>(string);
    }
}

struct x_digit_production
{
    static constexpr auto rule = dsl::capture(x_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, XDigitTests)
{
    EXPECT_PARSE_FAILURE<x_digit_production>("");

    std::unordered_set<char> valid_characters{ 'x', 'X' };
    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        auto it = valid_characters.find(c);
        if (it != valid_characters.end())
            EXPECT_PARSE_RESULT<x_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<x_digit_production>(string);
    }
}

struct hex_digit_production
{
    static constexpr auto rule = dsl::capture(hex_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, HexDigitTests)
{
    EXPECT_PARSE_FAILURE<hex_digit_production>("");

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
            EXPECT_PARSE_RESULT<hex_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<hex_digit_production>(string);
    }
}

struct octal_digit_production
{
    static constexpr auto rule = dsl::capture(octal_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, OctalDigitTests)
{
    EXPECT_PARSE_FAILURE<octal_digit_production>("");

    std::unordered_set<char> characters
    {
        'x', 'X',
        'z', 'Z', '?',
        '0', '1', '2', '3', '4', '5', '6', '7',
    };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<octal_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<octal_digit_production>(string);
    }
}

struct binary_digit_production
{
    static constexpr auto rule = dsl::capture(binary_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, BinaryDigitTests)
{
    EXPECT_PARSE_FAILURE<binary_digit_production>("");

    std::unordered_set<char> characters{ 'x', 'X', 'z', 'Z', '?', '0', '1', };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<binary_digit_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<binary_digit_production>(string);
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

    EXPECT_PARSE_RESULT<binary_base>("'sb", true);
    EXPECT_PARSE_RESULT<binary_base>("'Sb", true);
    EXPECT_PARSE_RESULT<binary_base>("'sB", true);
    EXPECT_PARSE_RESULT<binary_base>("'SB", true);

    EXPECT_PARSE_RESULT<binary_base>("'b", false);
    EXPECT_PARSE_RESULT<binary_base>("'B", false);
}

TEST(SV2017NumberTests, DecimalBaseTests)
{
    EXPECT_PARSE_FAILURE<decimal_base>("");
    EXPECT_PARSE_FAILURE<decimal_base>("a");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_FAILURE<decimal_base>("'");

    EXPECT_PARSE_RESULT<decimal_base>("'sd", true);
    EXPECT_PARSE_RESULT<decimal_base>("'Sd", true);
    EXPECT_PARSE_RESULT<decimal_base>("'sD", true);
    EXPECT_PARSE_RESULT<decimal_base>("'SD", true);

    EXPECT_PARSE_RESULT<decimal_base>("'d", false);
    EXPECT_PARSE_RESULT<decimal_base>("'D", false);
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

struct exp_production
{
    static constexpr auto rule = dsl::capture(exp);
    static constexpr auto value = lexy::as_string<std::string>;
};

TEST(SV2017NumberTests, ExponentTests)
{
    EXPECT_PARSE_FAILURE<exp_production>("");

    std::unordered_set<char> characters { 'e', 'E' };

    for (char c = CHAR_MIN; c < CHAR_MAX; ++c)
    {
        std::string string(1, c);

        if (characters.find(c) != characters.end())
            EXPECT_PARSE_RESULT<exp_production>(string, string);
        else
            EXPECT_PARSE_FAILURE<exp_production>(string);
    }
}

TEST(SV2017NumberTests, FixedPointNumberTests)
{
    EXPECT_PARSE_FAILURE<fixed_point_number>("");
    EXPECT_PARSE_FAILURE<fixed_point_number>("g");

    EXPECT_PARSE_FAILURE<fixed_point_number>("_1373.4189");
    EXPECT_PARSE_FAILURE<fixed_point_number>("1373._4189");
    EXPECT_PARSE_FAILURE<fixed_point_number>("_1373._4189");

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
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("114", "114");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4", "1_1_4");
    EXPECT_PARSE_FAILURE<non_zero_unsigned_number>("_1_1_4");
    EXPECT_PARSE_RESULT<non_zero_unsigned_number>("1_1_4_", "1_1_4_");
}

template<typename TProduction>
void test_hex_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'hgdead");
    EXPECT_PARSE_FAILURE<TProduction>("'h gdead");

    EXPECT_PARSE_RESULT<TProduction>(
        "'h deadbeef9876543210c",
        ast::integral_number_t{ std::nullopt, false, "deadbeef9876543210c", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'h1b",
        ast::integral_number_t{ std::nullopt, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'h1b",
        ast::integral_number_t{ std::nullopt, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'h 1b",
        ast::integral_number_t{ std::nullopt, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'h 1b",
        ast::integral_number_t{ std::nullopt, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        "8'h1b",
        ast::integral_number_t{ 8, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        "8 'h1b",
        ast::integral_number_t{ 8, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        "8'h 1b",
        ast::integral_number_t{ 8, false, "1b", });
    EXPECT_PARSE_RESULT<TProduction>(
        "8 'h 1b",
        ast::integral_number_t{ 8, false, "1b", });

    EXPECT_PARSE_RESULT<TProduction>(
        "'h4ad",
        ast::integral_number_t{ std::nullopt, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'h4ad",
        ast::integral_number_t{ std::nullopt, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'h 4ad",
        ast::integral_number_t{ std::nullopt, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'h 4ad",
        ast::integral_number_t{ std::nullopt, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        "12'h4ad",
        ast::integral_number_t{ 12, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        "12 'h4ad",
        ast::integral_number_t{ 12, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        "12'h 4ad",
        ast::integral_number_t{ 12, false, "4ad", });
    EXPECT_PARSE_RESULT<TProduction>(
        "12 'h 4ad",
        ast::integral_number_t{ 12, false, "4ad", });
}

TEST(SV2017NumberTests, HexNumberTests)
{
    test_hex_number_parsing<hex_number>();
}

template<typename TProduction>
void test_octal_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'o8765");
    EXPECT_PARSE_FAILURE<TProduction>("'o 8765");

    EXPECT_PARSE_RESULT<TProduction>(
        "'o 12345670",
        ast::integral_number_t{ std::nullopt, false, "12345670", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'o15",
        ast::integral_number_t{ std::nullopt, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'o15",
        ast::integral_number_t{ std::nullopt, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'o 15",
        ast::integral_number_t{ std::nullopt, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'o 15",
        ast::integral_number_t{ std::nullopt, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        "6'o15",
        ast::integral_number_t{ 6, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        "6 'o15",
        ast::integral_number_t{ 6, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        "6'o 15",
        ast::integral_number_t{ 6, false, "15", });
    EXPECT_PARSE_RESULT<TProduction>(
        "6 'o 15",
        ast::integral_number_t{ 6, false, "15", });

    EXPECT_PARSE_RESULT<TProduction>(
        "'o423",
        ast::integral_number_t{ std::nullopt, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'o423",
        ast::integral_number_t{ std::nullopt, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        "'o 423",
        ast::integral_number_t{ std::nullopt, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'o 423",
        ast::integral_number_t{ std::nullopt, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        "9'o423",
        ast::integral_number_t{ 9, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        "9 'o423",
        ast::integral_number_t{ 9, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        "9'o 423",
        ast::integral_number_t{ 9, false, "423", });
    EXPECT_PARSE_RESULT<TProduction>(
        "9 'o 423",
        ast::integral_number_t{ 9, false, "423", });
}

TEST(SV2017NumberTests, OctalNumberTests)
{
    test_octal_number_parsing<octal_number>();
}

template<typename TProduction>
void test_binary_number_parsing()
{
    EXPECT_PARSE_FAILURE<TProduction>("");
    EXPECT_PARSE_FAILURE<TProduction>("t");

    EXPECT_PARSE_FAILURE<TProduction>("'b2010");
    EXPECT_PARSE_FAILURE<TProduction>("'b 2010");

    EXPECT_PARSE_RESULT<TProduction>(
        "'b 1011011010",
        ast::integral_number_t { std::nullopt, false, "1011011010" });

    EXPECT_PARSE_RESULT<TProduction>(
        "'b10",
        ast::integral_number_t { std::nullopt, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'b10",
        ast::integral_number_t { std::nullopt, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        "'b 10",
        ast::integral_number_t { std::nullopt, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'b 10",
        ast::integral_number_t { std::nullopt, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        "2'b10",
        ast::integral_number_t { 2, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        "2 'b10",
        ast::integral_number_t { 2, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        "2'b 10",
        ast::integral_number_t { 2, false, "10" });
    EXPECT_PARSE_RESULT<TProduction>(
        "2 'b 10",
        ast::integral_number_t { 2, false, "10" });

    EXPECT_PARSE_RESULT<TProduction>(
        "'b010",
        ast::integral_number_t { std::nullopt, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'b010",
        ast::integral_number_t { std::nullopt, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        "'b 010",
        ast::integral_number_t { std::nullopt, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        " 'b 010",
        ast::integral_number_t { std::nullopt, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        "3'b010",
        ast::integral_number_t { 3, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        "3 'b010",
        ast::integral_number_t { 3, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        "3'b 010",
        ast::integral_number_t { 3, false, "010" });
    EXPECT_PARSE_RESULT<TProduction>(
        "3 'b 010",
        ast::integral_number_t { 3, false, "010" });
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

    EXPECT_PARSE_RESULT<TProduction>("0", ast::integral_number_t { std::nullopt, true, "0", });
    EXPECT_PARSE_RESULT<TProduction>("123", ast::integral_number_t { std::nullopt, true, "123", });

    EXPECT_PARSE_RESULT<TProduction>("'d0", ast::integral_number_t { std::nullopt, false, "0", });
    EXPECT_PARSE_RESULT<TProduction>("'d123", ast::integral_number_t { std::nullopt, false, "123", });
    EXPECT_PARSE_RESULT<TProduction>("'d 123", ast::integral_number_t { std::nullopt, false, "123", });

    EXPECT_PARSE_RESULT<TProduction>("20'd123", ast::integral_number_t { 20, false, "123", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd123", ast::integral_number_t { 20, false, "123", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd 123", ast::integral_number_t { 20, false, "123", });

    EXPECT_PARSE_RESULT<TProduction>("20'dx", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20'dX", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dx", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dX", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd x", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd X", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20'dx_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20'dX_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dx_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dX_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd x_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd X_", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20'dx__", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20'dX__", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dx__", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dX__", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd x__", ast::integral_number_t { 20, false, "X", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd X__", ast::integral_number_t { 20, false, "X", });

    EXPECT_PARSE_RESULT<TProduction>("20'dz", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'dZ", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'd?", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dz", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dZ", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd?", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd z", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd Z", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd ?", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'dz_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'dZ_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'd?_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dz_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dZ_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd?_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd z_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd Z_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd ?_", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'dz__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'dZ__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20'd?__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dz__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'dZ__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd?__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd z__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd Z__", ast::integral_number_t { 20, false, "Z", });
    EXPECT_PARSE_RESULT<TProduction>("20 'd ?__", ast::integral_number_t { 20, false, "Z", });
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

//TEST(SV2017NumberTests, NumberTests)
//{
//    test_integral_number_parsing<number>();
//    test_real_number_parsing<number>();
//}

