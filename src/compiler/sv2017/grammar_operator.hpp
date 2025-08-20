#ifndef SVS_COMPILER_SV2017_GRAMMAR_OPERATOR_H_
#define SVS_COMPILER_SV2017_GRAMMAR_OPERATOR_H_

#include <lexy/dsl/capture.hpp>
#include <string>

#include <lexy/callback/string.hpp>
#include <lexy/dsl.hpp>
#include <lexy/dsl/branch.hpp>

namespace svs::sv2017::grammar
{

namespace dsl = lexy::dsl;

struct unary_operator
{
    static constexpr auto rule =
        dsl::peek(dsl::lit_c<'~'>) >>
            (dsl::peek(LEXY_LIT("~&")) >> dsl::capture(LEXY_LIT("~&")) |
             dsl::peek(LEXY_LIT("~|")) >> dsl::capture(LEXY_LIT("~|")) |
             dsl::peek(LEXY_LIT("~^")) >> dsl::capture(LEXY_LIT("~^")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'~'>)) |
        dsl::peek(dsl::lit_c<'^'>) >>
            (dsl::peek(LEXY_LIT("^~")) >> dsl::capture(LEXY_LIT("^~")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'^'>)) |
        dsl::else_ >> dsl::capture(dsl::lit_c<'+'> / dsl::lit_c<'-'> /
                                   dsl::lit_c<'!'> / dsl::lit_c<'~'> /
                                   dsl::lit_c<'&'> / dsl::lit_c<'|'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

struct binary_operator
{
    static constexpr auto rule =
        dsl::peek(dsl::lit_c<'='>) >>
            (dsl::peek(LEXY_LIT("===")) >> dsl::capture(LEXY_LIT("===")) |
             dsl::peek(LEXY_LIT("==?")) >> dsl::capture(LEXY_LIT("==?")) |
             dsl::else_ >> dsl::capture(LEXY_LIT("=="))) |
        dsl::peek(dsl::lit_c<'!'>) >>
            (dsl::peek(LEXY_LIT("!==")) >> dsl::capture(LEXY_LIT("!==")) |
             dsl::peek(LEXY_LIT("!=?")) >> dsl::capture(LEXY_LIT("!=?")) |
             dsl::else_ >> dsl::capture(LEXY_LIT("!="))) |
        dsl::peek(dsl::lit_c<'&'>) >>
            (dsl::peek(LEXY_LIT("&&")) >> dsl::capture(LEXY_LIT("&&")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'&'>)) |
        dsl::peek(dsl::lit_c<'|'>) >>
            (dsl::peek(LEXY_LIT("||")) >> dsl::capture(LEXY_LIT("||")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'|'>)) |
        dsl::peek(dsl::lit_c<'*'>) >>
            (dsl::peek(LEXY_LIT("**")) >> dsl::capture(LEXY_LIT("**")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'*'>)) |
        dsl::peek(dsl::lit_c<'<'>) >>
            (dsl::peek(LEXY_LIT("<<<")) >> dsl::capture(LEXY_LIT("<<<")) |
             dsl::peek(LEXY_LIT("<<")) >> dsl::capture(LEXY_LIT("<<")) |
             dsl::peek(LEXY_LIT("<=")) >> dsl::capture(LEXY_LIT("<=")) |
             dsl::peek(LEXY_LIT("<->")) >> dsl::capture(LEXY_LIT("<->")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'<'>)) |
        dsl::peek(dsl::lit_c<'>'>) >>
            (dsl::peek(LEXY_LIT(">>>")) >> dsl::capture(LEXY_LIT(">>>")) |
             dsl::peek(LEXY_LIT(">>")) >> dsl::capture(LEXY_LIT(">>")) |
             dsl::peek(LEXY_LIT(">=")) >> dsl::capture(LEXY_LIT(">=")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'>'>)) |
        dsl::peek(dsl::lit_c<'^'>) >>
            (dsl::peek(LEXY_LIT("^~")) >> dsl::capture(LEXY_LIT("^~")) |
             dsl::else_ >> dsl::capture(dsl::lit_c<'^'>)) |
        dsl::peek(LEXY_LIT("~^")) >> dsl::capture(LEXY_LIT("~^")) |
        dsl::peek(LEXY_LIT("->")) >> dsl::capture(LEXY_LIT("->")) |
        dsl::else_ >> dsl::capture(dsl::lit_c<'+'> / dsl::lit_c<'-'> /
                                   dsl::lit_c<'/'> / dsl::lit_c<'%'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

} // namespace svs::sv2017::grammar

#endif // SVS_COMPILER_SV2017_GRAMMAR_OPERATOR_H_
