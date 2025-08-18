#ifndef SVS_COMPILER_SV2017_GRAMMAR_IDENTIFIER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_IDENTIFIER_H_

#include <string>

#include <lexy/callback/string.hpp>
#include <lexy/dsl.hpp>

namespace svs::sv2017::grammar
{

namespace dsl = lexy::dsl;

//
// System Task or Function Identifier
//
// system_tf_identifier ::= $[ a-zA-Z0-9_$ ] { [ a-zA-Z0-9_$ ] }
//
struct system_tf_identifier
{
    static constexpr auto rule = [] {
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
    static constexpr auto rule = [] {
        auto head = dsl::ascii::alpha_underscore;
        auto tail = dsl::ascii::alpha_digit_underscore / dsl::dollar_sign;
        return dsl::identifier(head, tail);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Escaped Identifier
//
// escaped_identifier ::= \ {any_printable_ASCII_character_except_white_space}
// white_space
//
struct escaped_identifier
{
    static constexpr auto rule = [] {
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
    static constexpr auto rule =
        dsl::p<simple_identifier> | dsl::p<escaped_identifier>;

    static constexpr auto value = lexy::forward<std::string>;
};

} // namespace svs::grammar::sv2017

#endif // SVS_COMPILER_SV2017_GRAMMAR_IDENTIFIER_H_
