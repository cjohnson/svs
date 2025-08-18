#ifndef SVS_COMPILER_SV2017_GRAMMAR_STRING_LITERAL_H_
#define SVS_COMPILER_SV2017_GRAMMAR_STRING_LITERAL_H_

#include <string>

#include <lexy/callback/string.hpp>
#include <lexy/dsl.hpp>

namespace svs::sv2017::grammar
{

namespace dsl = lexy::dsl;

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

    static constexpr auto rule = [] {
        auto character_rule = dsl::ascii::character - dsl::ascii::control;

        auto escape_rule =
            dsl::backslash_escape.rule(dsl::ascii::control)
                .symbol<escaped_symbols>()
                .rule(
                    dsl::integer<int, dsl::octal>(dsl::n_digits<3, dsl::octal>))
                .rule(
                    dsl::integer<int, dsl::octal>(dsl::n_digits<2, dsl::octal>))
                .rule(dsl::integer<int, dsl::octal>(dsl::digit<dsl::octal>))
                .rule(dsl::lit_c<'x'> >>
                      (dsl::integer<int, dsl::hex>(dsl::n_digits<2, dsl::hex>) |
                       dsl::integer<int, dsl::hex>(dsl::digit<dsl::hex>)));
        return dsl::quoted(character_rule, escape_rule);
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

} // namespace svs::sv2017::grammar

#endif // SVS_COMPILER_SV2017_GRAMMAR_STRING_LITERAL_H_
