#ifndef SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_

#include <lexy/dsl/digit.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/grammar.hpp>
#include <string>

#include <lexy/dsl.hpp>
#include <lexy/callback.hpp>

namespace svs::grammar::sv2017
{

namespace dsl = lexy::dsl;


constexpr auto _x_set = dsl::lit_c<'x'> / dsl::lit_c<'X'>;
constexpr auto _z_set = dsl::lit_c<'z'> / dsl::lit_c<'Z'> / dsl::lit_c<'?'>;
constexpr auto _z_or_x_cset = (_x_set / _z_set) - dsl::lit_c<'?'>;

constexpr auto _hex_digit = _x_set / _z_set / dsl::digit<dsl::hex>;

constexpr auto _hex_indicator = dsl::lit_c<'h'> / dsl::lit_c<'H'>;
constexpr auto _signedness_indicator = dsl::lit_c<'s'> / dsl::lit_c<'S'>;

//
// Z (High-Impedance) or X (Unknown) value
//
// z_or_x ::= x | X | z | Z
//
struct z_or_x
{
    static constexpr auto rule = dsl::capture(_z_or_x_cset);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Unbased, unsized literal
//
// unbased_unsized_literal ::= '0 | '1 | 'z_or_x
//
struct unbased_unsized_literal
{
    static constexpr auto rule = dsl::lit_c<'\''> + dsl::capture(dsl::digit<dsl::binary> / _z_or_x_cset);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Z (High-Impedance) digit
//
// z_digit ::= z | Z | ?
//
struct z_digit
{
    static constexpr auto rule = dsl::capture(_z_set);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// X (Unknown) digit
//
// x_digit ::= x | X
//
struct x_digit
{
    static constexpr auto rule = dsl::capture(_x_set);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Hex digit
//
// hex_digit ::= x_digit | z_digit
//               | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//               | a | b | c | d | e | f
//               | A | B | C | D | E | F
//
struct hex_digit
{
    static constexpr auto rule = dsl::capture(_hex_digit);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Hex base
//
// hex_base ::= '[s|S]h | '[s|S]H
//
struct hex_base : lexy::token_production
{
private:
    struct implicit_signed_hex_base : lexy::transparent_production
    {
        static constexpr auto rule = _hex_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "h"; });
    };

    struct explicit_signed_hex_base : lexy::transparent_production
    {
        static constexpr auto rule = _signedness_indicator >> _hex_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "sh"; });
    };

public:
    static constexpr auto rule =
        dsl::lit_c<'\''> >> (dsl::p<implicit_signed_hex_base> | dsl::p<explicit_signed_hex_base>);
    static constexpr auto value = lexy::forward<std::string>;
};

//
// Hex value
//
// hex_value ::= hex_digit { _ | hex_digit }
//
struct hex_value
{
    static constexpr auto rule = dsl::identifier(_hex_digit, _hex_digit / dsl::lit_c<'_'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Non-zero unsigned number
//
// non_zero_unsigned_number ::= non_zero_decimal_digit { _ | decimal_digit} 
//
struct non_zero_unsigned_number
{
    static constexpr auto rule = dsl::identifier(
        dsl::digit<dsl::decimal> - dsl::zero,
        dsl::digit<dsl::decimal> / dsl::lit_c<'_'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Size
//
// size ::= non_zero_unsigned_number
//
typedef non_zero_unsigned_number size;

//
// Hex number
//
// hex_number ::= [ size ] hex_base hex_value
//
struct hex_number : lexy::token_production
{
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule = dsl::opt(dsl::p<size>) + dsl::p<hex_base> + dsl::p<hex_value>;
};

}

#endif // SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
