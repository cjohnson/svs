#ifndef SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_

#include <string>

#include <lexy/dsl.hpp>
#include <lexy/callback.hpp>

#include "ast_number.h"

namespace svs::grammar::sv2017
{

namespace dsl = lexy::dsl;

namespace ast = svs::ast::sv2017;

//
// Z (High-Impedance) or X (Unknown) value
//
// z_or_x ::= x | X | z | Z
//
struct z_or_x
{
    static constexpr auto rule = dsl::capture(
        dsl::lit_c<'x'> / dsl::lit_c<'X'> / dsl::lit_c<'z'> / dsl::lit_c<'Z'>);

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Unbased, unsized literal
//
// unbased_unsized_literal ::= '0 | '1 | 'z_or_x
//
struct unbased_unsized_literal
{
    static constexpr auto rule = []
    {
        auto literal_value =
            dsl::capture(dsl::lit_c<'0'> / dsl::lit_c<'1'>)
          | dsl::p<z_or_x>;

        return dsl::lit_c<'\''> + literal_value;
    }();

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Z (High-Impedance) digit
//
// z_digit ::= z | Z | ?
//
struct z_digit
{
    static constexpr auto rule = dsl::capture(
        dsl::lit_c<'z'> / dsl::lit_c<'Z'> / dsl::lit_c<'?'>);

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// X (Unknown) digit
//
// x_digit ::= x | X
//
struct x_digit
{
    static constexpr auto rule = dsl::capture(
        dsl::lit_c<'x'> / dsl::lit_c<'X'>);

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
    static constexpr auto rule =
        dsl::p<x_digit>
      | dsl::p<z_digit>
      | dsl::capture(dsl::digit<dsl::hex>);

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Hex base
//
// hex_base ::= '[s|S]h | '[s|S]H
//
struct hex_base
{
private:
    static constexpr auto signage_indicator = dsl::lit_c<'s'> | dsl::lit_c<'S'>;
    static constexpr auto hex_indicator = dsl::lit_c<'h'> | dsl::lit_c<'H'>;

    struct explicit_signed_hex_base
    {
        static constexpr auto rule = signage_indicator >> hex_indicator;
        static constexpr auto value = lexy::callback<ast::signedness>(
            []() { return ast::signedness::SIGNED; });
    };

    struct implicit_signed_hex_base
    {
        static constexpr auto rule = hex_indicator;
        static constexpr auto value = lexy::callback<ast::signedness>(
            []() { return ast::signedness::UNSIGNED; });
    };

public:
    static constexpr auto rule =
        dsl::lit_c<'\''> >>
        (dsl::p<explicit_signed_hex_base> | dsl::p<implicit_signed_hex_base>);

    static constexpr auto value = lexy::forward<ast::signedness>;
};


//
// Hex value
//
// hex_value ::= hex_digit { _ | hex_digit }
//
struct hex_value
{
private:
    struct sv_hex : dsl::char_class_base<sv_hex>
    {
        static LEXY_CONSTEVAL auto char_class_name()
        {
            return "digit.sv_hex";
        }

        static LEXY_CONSTEVAL auto char_class_ascii()
        {
            lexy::_detail::ascii_set result;
            result.insert('0', '9');
            result.insert('a', 'f');
            result.insert('A', 'F');
            result.insert('x');
            result.insert('X');
            result.insert('z');
            result.insert('Z');
            return result;
        }

        static constexpr unsigned digit_radix = 16;
    };

public:
    static constexpr auto rule = dsl::capture(
        dsl::digits<sv_hex>.sep(dsl::digit_sep_underscore));

    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Non-zero unsigned number
//
// non_zero_unsigned_number ::= non_zero_decimal_digit { _ | decimal_digit} 
//
struct non_zero_unsigned_number
{
    static constexpr auto rule =
        dsl::digits<>.sep(dsl::digit_sep_underscore).no_leading_zero();

    static constexpr auto value = lexy::forward<unsigned int>;
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
struct hex_number
{
    static constexpr auto whitespace = dsl::ascii::space;

    static constexpr auto rule = dsl::opt(dsl::p<size>) + dsl::p<hex_base> + dsl::p<hex_value>;
};

}

#endif // SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
