#ifndef SVS_SV2017_GRAMMAR_H_
#define SVS_SV2017_GRAMMAR_H_

#include <lexy/action/match.hpp>
#include <lexy/dsl/ascii.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/dsl/whitespace.hpp>
#include <lexy/grammar.hpp>
#include <string>

#include <lexy/dsl.hpp>
#include <lexy/callback/string.hpp>

namespace
{

namespace sv2017
{

namespace dsl = lexy::dsl;

// A.9.3 Identifiers

/**
 * Escaped identifier grammar
 *
 * escaped_identifier ::= \ {any_printable_ASCII_character_except_white_space} white_space
 */
struct escaped_identifier;

/**
 * Simple identifier grammar
 *
 * simple_identifier ::= [ a-zA-Z_ ] { [ a-zA-Z0-9_$ ] } 
 */
struct simple_identifier;

/**
 * System task or function identifier grammar (A.9.3)
 *
 * system_tf_identifier ::= $[ a-zA-Z0-9_$ ]{ [ a-zA-Z0-9_$ ] }
 */
struct system_tf_identifier;

// A.9.4 White space

/**
 * White space grammar
 *
 * white_space ::= space | tab | newline | eof
 */
struct white_space
{
    static constexpr auto rule = dsl::whitespace(
        dsl::lit_c<' '> | dsl::lit_c<'\t'> | dsl::newline | dsl::eof);

    static constexpr auto value = lexy::as_string<std::string>;
};

struct escaped_identifier
{
    static constexpr auto rule = []
    {
        return dsl::lit_c<'\\'> + dsl::while_(dsl::p<white_space>);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

struct simple_identifier
{
    static constexpr auto rule = []
    {
        auto head = dsl::ascii::alpha_underscore;
        auto tail = dsl::ascii::alpha_digit_underscore / dsl::lit_c<'$'>;
        return dsl::identifier(head, tail);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

struct system_tf_identifier
{
    static constexpr auto rule = []
    {
        auto dollar_sign_prefix = dsl::lit_c<'$'>;
        auto head = dsl::ascii::alpha_digit_underscore / dsl::lit_c<'$'>;
        return dollar_sign_prefix + dsl::identifier(head);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};


} // sv2017
} // namespace

#endif // SVS_SV2017_GRAMMAR_H_

