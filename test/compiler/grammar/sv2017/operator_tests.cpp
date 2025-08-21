#include <gtest/gtest.h>
#include <lexy/callback/string.hpp>

#include "../../../../src/compiler/sv2017/grammar_operator.hpp"

#include "../grammar_test_utils.hpp"

using namespace svs::sv2017::grammar;

TEST(SV2017OperatorTests, UnaryOperatorTests)
{
    EXPECT_PARSE_FAILURE<unary_operator>("");
    EXPECT_PARSE_FAILURE<unary_operator>("a");
    EXPECT_PARSE_FAILURE<unary_operator>("]");

    EXPECT_PARSE_RESULT<unary_operator>("+", "+");
    EXPECT_PARSE_RESULT<unary_operator>("-", "-");
    EXPECT_PARSE_RESULT<unary_operator>("!", "!");
    EXPECT_PARSE_RESULT<unary_operator>("~", "~");
    EXPECT_PARSE_RESULT<unary_operator>("&", "&");
    EXPECT_PARSE_RESULT<unary_operator>("~&", "~&");
    EXPECT_PARSE_RESULT<unary_operator>("|", "|");
    EXPECT_PARSE_RESULT<unary_operator>("~|", "~|");
    EXPECT_PARSE_RESULT<unary_operator>("^", "^");
    EXPECT_PARSE_RESULT<unary_operator>("~^", "~^");
    EXPECT_PARSE_RESULT<unary_operator>("^~", "^~");
}

TEST(SV2017OperatorTests, BinaryOperatorTests)
{
    EXPECT_PARSE_FAILURE<binary_operator>("");
    EXPECT_PARSE_FAILURE<binary_operator>("b");
    EXPECT_PARSE_FAILURE<binary_operator>("]");

    EXPECT_PARSE_RESULT<binary_operator>("+", "+");
    EXPECT_PARSE_RESULT<binary_operator>("-", "-");
    EXPECT_PARSE_RESULT<binary_operator>("*", "*");
    EXPECT_PARSE_RESULT<binary_operator>("/", "/");
    EXPECT_PARSE_RESULT<binary_operator>("%", "%");
    EXPECT_PARSE_RESULT<binary_operator>("==", "==");
    EXPECT_PARSE_RESULT<binary_operator>("!=", "!=");
    EXPECT_PARSE_RESULT<binary_operator>("===", "===");
    EXPECT_PARSE_RESULT<binary_operator>("==?", "==?");
    EXPECT_PARSE_RESULT<binary_operator>("!=?", "!=?");
    EXPECT_PARSE_RESULT<binary_operator>("&&", "&&");
    EXPECT_PARSE_RESULT<binary_operator>("||", "||");
    EXPECT_PARSE_RESULT<binary_operator>("**", "**");
    EXPECT_PARSE_RESULT<binary_operator>("<", "<");
    EXPECT_PARSE_RESULT<binary_operator>("<=", "<=");
    EXPECT_PARSE_RESULT<binary_operator>(">", ">");
    EXPECT_PARSE_RESULT<binary_operator>(">=", ">=");
    EXPECT_PARSE_RESULT<binary_operator>("&", "&");
    EXPECT_PARSE_RESULT<binary_operator>("|", "|");
    EXPECT_PARSE_RESULT<binary_operator>("^", "^");
    EXPECT_PARSE_RESULT<binary_operator>("^~", "^~");
    EXPECT_PARSE_RESULT<binary_operator>("~^", "~^");
    EXPECT_PARSE_RESULT<binary_operator>(">>", ">>");
    EXPECT_PARSE_RESULT<binary_operator>("<<", "<<");
    EXPECT_PARSE_RESULT<binary_operator>(">>>", ">>>");
    EXPECT_PARSE_RESULT<binary_operator>("<<<", "<<<");
    EXPECT_PARSE_RESULT<binary_operator>("->", "->");
    EXPECT_PARSE_RESULT<binary_operator>("<->", "<->");
}

TEST(SV2017OperatorTests, IncOrDecOperatorTests)
{
    EXPECT_PARSE_FAILURE<inc_or_dec_operator>("");
    EXPECT_PARSE_FAILURE<inc_or_dec_operator>("x");
    EXPECT_PARSE_FAILURE<inc_or_dec_operator>("&");
    EXPECT_PARSE_FAILURE<inc_or_dec_operator>("+");
    EXPECT_PARSE_FAILURE<inc_or_dec_operator>("-");

    EXPECT_PARSE_RESULT<inc_or_dec_operator>("++", "++");
    EXPECT_PARSE_RESULT<inc_or_dec_operator>("--", "--");
}
