#ifndef SVSC_GRAMMAR_SV2017_HPP_
#define SVSC_GRAMMAR_SV2017_HPP_

#include <string>

#include <lexy/callback.hpp>
#include <lexy/dsl.hpp>
#include <lexy/dsl/ascii.hpp>
#include <lexy/dsl/delimited.hpp>
#include <lexy/dsl/digit.hpp>
#include <lexy/dsl/integer.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/dsl/literal.hpp>
#include <lexy/dsl/punctuator.hpp>
#include <lexy/grammar.hpp>

namespace
{
namespace sv2017
{

namespace dsl = lexy::dsl;

//
// System Task or Function Identifier
//
// system_tf_identifier ::= $[ a-zA-Z0-9_$ ] { [ a-zA-Z0-9_$ ] }
//
struct system_tf_identifier
{
    static constexpr auto rule = []
    {
        auto head = dsl::ascii::alpha_digit_underscore / dsl::dollar_sign;
        return dsl::dollar_sign + dsl::identifier(head);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Simple Identifier
//
// simple_identifier ::= [ a-zA-Z_ ] { [ a-zA-Z0-9_$ ] }
//
struct simple_identifier
{
    static constexpr auto rule = []
    {
        auto head = dsl::ascii::alpha_underscore;
        auto tail = dsl::ascii::alpha_digit_underscore / dsl::dollar_sign;
        return dsl::identifier(head, tail);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Escaped Identifier
//
// escaped_identifier ::= \ {any_printable_ASCII_character_except_white_space} white_space
//
struct escaped_identifier
{
    static constexpr auto rule = []
    {
        auto head = dsl::ascii::print - dsl::ascii::space;
        return dsl::lit_c<'\\'> >> dsl::identifier(head);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Identifier
//
// identifier ::=
//     simple_identifier
//   | escaped_identifier 
//
struct identifier
{
    static constexpr auto rule = dsl::p<simple_identifier> | dsl::p<escaped_identifier>;

    static constexpr auto value = lexy::forward<std::string>;
};

//
// String Literal
//
// string_literal ::= " { Any_ASCII_Characters } "
//
struct string_literal
{
    static constexpr auto escaped_symbols = lexy::symbol_table<char>
        .map<'n'>('\n')
        .map<'t'>('\t')
        .map<'\\'>('\\')
        .map<'"'>('"')
        .map<'v'>('\v')
        .map<'f'>('\f')
        .map<'a'>('\a');

    static constexpr auto rule = []
    {
        auto character_rule = dsl::ascii::character - dsl::ascii::control;

        auto escape_rule = dsl::backslash_escape
            .rule(dsl::ascii::control)
            .symbol<escaped_symbols>()
            .rule(dsl::integer<int, dsl::octal>(dsl::n_digits<3, dsl::octal>))
            .rule(dsl::integer<int, dsl::octal>(dsl::n_digits<2, dsl::octal>))
            .rule(dsl::integer<int, dsl::octal>(dsl::digit<dsl::octal>))
            .rule(dsl::lit_c<'x'> >> (
                dsl::integer<int, dsl::hex>(dsl::n_digits<2, dsl::hex>)
              | dsl::integer<int, dsl::hex>(dsl::digit<dsl::hex>)));
        return dsl::quoted(character_rule, escape_rule);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

}
}

#endif // SVSC_GRAMMAR_SV2017_HPP_

