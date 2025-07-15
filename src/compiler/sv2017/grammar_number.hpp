#ifndef SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_

#include <array>
#include <sstream>
#include <string>
#include <sstream>
#include <optional>

#include <lexy/callback.hpp>
#include <lexy/callback/fold.hpp>
#include <lexy/dsl/digit.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/dsl.hpp>
#include <lexy/grammar.hpp>
#include <sys/types.h>

#include "ast_number.h"

namespace svs::grammar::sv2017
{

namespace dsl = lexy::dsl;
namespace ast = svs::ast::sv2017;

constexpr auto _x = dsl::lit_c<'x'> / dsl::lit_c<'X'>;
constexpr auto _z = dsl::lit_c<'z'> / dsl::lit_c<'Z'> / dsl::lit_c<'?'>;
constexpr auto _z_or_x = (_x/ _z) - dsl::lit_c<'?'>;

constexpr auto _hex = _x / _z / dsl::digit<dsl::hex>;
constexpr auto _octal = _x / _z / dsl::digit<dsl::octal>;
constexpr auto _binary = _x / _z / dsl::digit<dsl::binary>;

constexpr auto _hex_indicator = dsl::lit_c<'h'> / dsl::lit_c<'H'>;
constexpr auto _octal_indicator = dsl::lit_c<'o'> / dsl::lit_c<'O'>;
constexpr auto _binary_indicator = dsl::lit_c<'b'> / dsl::lit_c<'B'>;
constexpr auto _decimal_indicator = dsl::lit_c<'d'> / dsl::lit_c<'D'>;
constexpr auto _signedness_indicator = dsl::lit_c<'s'> / dsl::lit_c<'S'>;

constexpr auto _exp = dsl::lit_c<'e'> / dsl::lit_c<'E'>;
constexpr auto _sign = dsl::lit_c<'+'> / dsl::lit_c<'-'>;

//
// Z (High-Impedance) or X (Unknown) value
//
// z_or_x ::= x | X | z | Z
//
struct z_or_x
{
    static constexpr auto rule = dsl::capture(_z_or_x);
    static constexpr auto value = lexy::callback<ast::logic_value_t>(
        [](auto lexeme)
        {
            char c = std::tolower(lexeme[0]);
            switch (c)
            {
            case 'x':
                return ast::logic_value_t::_X;
            case 'z':
                return ast::logic_value_t::_Z;
            default:
                return ast::logic_value_t::_X;
            }
        });
};

//
// Unbased, unsized literal
//
// unbased_unsized_literal ::= '0 | '1 | 'z_or_x
//
struct unbased_unsized_literal
{
    static constexpr auto rule = dsl::lit_c<'\''> + dsl::capture(dsl::digit<dsl::binary> / _z_or_x);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Z (High-Impedance) digit
//
// z_digit ::= z | Z | ?
//
struct z_digit
{
    static constexpr auto rule = _z;
    static constexpr auto value = lexy::callback<ast::logic_value_t>(
        [](){ return ast::logic_value_t::_Z; });
};

//
// X (Unknown) digit
//
// x_digit ::= x | X
//
struct x_digit
{
    static constexpr auto rule = _x;
    static constexpr auto value = lexy::callback<ast::logic_value_t>(
        [](){ return ast::logic_value_t::_X; });
};

//
// Deconstruct a hex character like 'a' into logic value bits.
//
// Examples:
// 'a' => '1010'
// 'X' => 'XXXX'
//
static constexpr std::array<ast::logic_value_t, 4> deconstruct_hex_to_bits(
    char hex_char)
{
    hex_char = std::isalpha(hex_char) ? std::tolower(hex_char) : hex_char;

    if (hex_char == 'x')
    {
        return std::array<ast::logic_value_t, 4>
        {
            ast::logic_value_t::_X,
            ast::logic_value_t::_X,
            ast::logic_value_t::_X,
            ast::logic_value_t::_X,
        };
    }

    if (hex_char == 'z' || hex_char == '?')
    {
        return std::array<ast::logic_value_t, 4>
        {
            ast::logic_value_t::_Z,
            ast::logic_value_t::_Z,
            ast::logic_value_t::_Z,
            ast::logic_value_t::_Z,
        };
    }

    u_int8_t mask = std::isdigit(hex_char)
        ? hex_char - '0'
        : hex_char - 'a' + 10;

    return std::array<ast::logic_value_t, 4>
    {
        (mask & 1<<0) ? ast::logic_value_t::_1 : ast::logic_value_t::_0,
        (mask & 1<<1) ? ast::logic_value_t::_1 : ast::logic_value_t::_0,
        (mask & 1<<2) ? ast::logic_value_t::_1 : ast::logic_value_t::_0,
        (mask & 1<<3) ? ast::logic_value_t::_1 : ast::logic_value_t::_0,
    };
}

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
    static constexpr auto rule = dsl::capture(_hex);
    static constexpr auto value = lexy::callback<std::array<ast::logic_value_t, 4>>(
        [](auto lexeme) { return deconstruct_hex_to_bits((char)lexeme[0]); });
};

//
// Octal digit
//
// octal_digit ::= x_digit | z_digit | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
//
struct octal_digit
{
    static constexpr auto rule = dsl::capture(_octal);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// (B)inary dig(it)
//
// binary_digit ::= x_digit | z_digit | 0 | 1
//
struct binary_digit
{
    static constexpr auto rule = dsl::capture(_binary);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Hex base
//
// hex_base ::= '[s|S]h | '[s|S]H
//
struct hex_base
{
    static constexpr auto rule = dsl::lit_c<'\''> + (
        dsl::capture(_signedness_indicator) >> _hex_indicator |
        _hex_indicator);
    static constexpr auto value = lexy::callback<bool>(
        []() { return false; },
        [](auto _) { (void)_; return true; });
};

//
// Octal base
//
// octal_base ::= '[s|S]o | '[s|S]O
//
struct octal_base
{
private:
    struct implicit_signedness_octal_base
    {
        static constexpr auto rule = _octal_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "o"; });
    };

    struct explicit_signedness_octal_base
    {
        static constexpr auto rule = _signedness_indicator >> _octal_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "so"; });
    };

public:
    static constexpr auto rule = dsl::lit_c<'\''> >>
        (dsl::p<implicit_signedness_octal_base> | dsl::p<explicit_signedness_octal_base>);
    static constexpr auto value = lexy::forward<std::string>;
};

//
// Binary base
//
// binary_base ::= '[s|S]b | '[s|S]B
//
struct binary_base
{
private:
    struct implicit_signedness_binary_base
    {
        static constexpr auto rule = _binary_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "b"; });
    };

    struct explicit_signedness_binary_base
    {
        static constexpr auto rule = _signedness_indicator >> _binary_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "sb"; });
    };

public:
    static constexpr auto rule = dsl::lit_c<'\''> >>
        (dsl::p<implicit_signedness_binary_base> | dsl::p<explicit_signedness_binary_base>);
    static constexpr auto value = lexy::forward<std::string>;
};

//
// Decimal base
//
// decimal_base ::= '[s|S]d | '[s|S]D
//
struct decimal_base
{
private:
    struct implicit_signedness_decimal_base
    {
        static constexpr auto rule = _decimal_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "d"; });
    };

    struct explicit_signedness_decimal_base
    {
        static constexpr auto rule = _signedness_indicator >> _decimal_indicator;
        static constexpr auto value = lexy::callback<std::string>([]() { return "sd"; });
    };

public:
    static constexpr auto rule = dsl::lit_c<'\''> >>
        (dsl::p<implicit_signedness_decimal_base> | dsl::p<explicit_signedness_decimal_base>);
    static constexpr auto value = lexy::forward<std::string>;
};

//
// Deconstruct a hex string like 'aX' into logic value bits.
//
// Examples:
// 'a', 'X' => '1010XXXX'
//
static constexpr std::vector<ast::logic_value_t> deconstruct_hex_to_bits(
    char head, std::optional<std::string> tail)
{
    std::vector<ast::logic_value_t> result;

    std::array<ast::logic_value_t, 4> nibble =
        deconstruct_hex_to_bits(head);
    for (const auto& bit : nibble)
    {
        result.push_back(bit);
    }

    if (!tail.has_value())
    {
        return result;
    }

    for (const char &c : tail.value())
    {
        if (c == '_')
        {
            continue;
        }

        std::array<ast::logic_value_t, 4> nibble =
            deconstruct_hex_to_bits(c);
        for (const auto& bit : nibble)
        {
            result.push_back(bit);
        }
    }

    return result;
}

//
// Hex value
//
// hex_value ::= hex_digit { _ | hex_digit }
//
struct hex_value
{
private:
    struct _head
    {
        static constexpr auto rule = dsl::capture(_hex);
        static constexpr auto value = lexy::as_string<std::string>;
    };
    struct _tail
    {
        static constexpr auto rule = dsl::list(dsl::capture(_hex / dsl::lit_c<'_'>));
        static constexpr auto value = lexy::as_string<std::string>;
    };

public:
    static constexpr auto rule = dsl::p<_head> + dsl::opt(dsl::p<_tail>);
    static constexpr auto value =
        lexy::callback<std::vector<ast::logic_value_t>>(
            [](std::string head, std::optional<std::string> tail)
            { return deconstruct_hex_to_bits(head[0], tail); });
};

//
// Octal value
//
// octal_value ::= octal_digit { _ | octal_digit } 
//
struct octal_value
{
    static constexpr auto rule = dsl::identifier(_octal, _octal / dsl::lit_c<'_'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Binary value
//
// binary_value ::= binary_digit { _ | binary_digit }
//
struct binary_value
{
    static constexpr auto rule = dsl::identifier(_binary, _binary / dsl::lit_c<'_'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Unsigned number
//
// unsigned_number ::= decimal_digit { _ | decimal_digit }
//
struct unsigned_number
{
    static constexpr auto rule = dsl::identifier(
        dsl::digit<dsl::decimal>,
        dsl::digit<dsl::decimal> / dsl::lit_c<'_'>);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Exponent
//
// exp ::= e | E
//
struct exp
{
    static constexpr auto rule = dsl::capture(_exp);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Fixed-point number
//
// fixed_point_number ::= unsigned_number . unsigned_number
//
struct fixed_point_number
{
    static constexpr auto rule = dsl::p<unsigned_number> >> dsl::lit_c<'.'> >> dsl::p<unsigned_number>;
    static constexpr auto value = lexy::callback<std::string>(
        [](std::string integer_part, std::string fractional_part)
        {
            return integer_part + "." + fractional_part;
        });
};

//
// Sign
//
// sign ::= + | -
//
struct sign
{
    static constexpr auto rule = dsl::capture(_sign);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Real number
//
// real_number ::=
//     fixed_point_number
//     | unsigned_number [ . unsigned_number ] exp [ sign ] unsigned_number 
//
struct real_number
{
    static constexpr auto rule =
        dsl::p<unsigned_number> +
        dsl::opt(dsl::period >> dsl::p<unsigned_number>) +
        dsl::if_(_exp >> (dsl::opt(dsl::p<sign>) + dsl::p<unsigned_number>));
    static constexpr auto value = lexy::callback<std::string>(
        [](std::string integer_part,
           std::optional<std::string> fractional_part)
        {
            std::stringstream ss;
            ss << integer_part;
            if (fractional_part.has_value())
            {
                ss << '.';
                ss << fractional_part.value();
            }
            return ss.str();
        },
        [](std::string integer_part,
           std::optional<std::string> fractional_part,
           std::optional<std::string> sign,
           std::string exponent_part)
        {
            std::stringstream ss;
            ss << integer_part;
            if (fractional_part.has_value())
            {
                ss << '.';
                ss << fractional_part.value();
            }
            ss << 'e';
            if (sign.has_value())
            {
                ss << sign.value();
            }
            ss << exponent_part;
            return ss.str();
        });
};

//
// Deconstruct an unsigned number like '1_2' into an integer.
//
// Examples:
// '1_2' => 12
//
static uint64_t unsigned_number_to_int(
    char head,
    std::optional<std::string> tail)
{
    std::stringstream ss;
    ss << head;

    if (!tail.has_value())
    {
        return std::stoull(ss.str());
    }

    for (const char &c : tail.value())
    {
        if (c == '_')
        {
            continue;
        }
        ss << c;
    }

    return std::stoull(ss.str());
}

//
// Non-zero unsigned number
//
// non_zero_unsigned_number ::= non_zero_decimal_digit { _ | decimal_digit }
//
struct non_zero_unsigned_number
{
private:
    struct _head
    {
        static constexpr auto rule =
            dsl::capture(dsl::digit<dsl::decimal> - dsl::zero);
        static constexpr auto value = lexy::as_string<std::string>;
    };
    struct _tail
    {
        static constexpr auto rule =
            dsl::list(dsl::capture(dsl::digit<dsl::decimal> / dsl::lit_c<'_'>));
        static constexpr auto value = lexy::as_string<std::string>;
    };

public:
    static constexpr auto rule = dsl::p<_head> + dsl::opt(dsl::p<_tail>);
    static constexpr auto value =
        lexy::callback<uint64_t>(
            [](std::string head, std::optional<std::string> tail)
            { return unsigned_number_to_int(head[0], tail); });
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
    static constexpr auto rule =
        dsl::opt(dsl::peek(dsl::p<size>) >> dsl::p<size>) + dsl::p<hex_base> + dsl::p<hex_value>;
    static constexpr auto value = lexy::construct<ast::integer_literal_constant_t>;
};

//
// Octal number
//
// octal_number ::= [ size ] octal_base octal_value
//
struct octal_number
{
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule =
        dsl::opt(dsl::peek(dsl::p<size>) >> dsl::p<size>) + dsl::p<octal_base> + dsl::p<octal_value>;
};

//
// Binary number
//
// binary_number ::= [ size ] binary_base binary_value
//
struct binary_number
{
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule =
        dsl::opt(dsl::peek(dsl::p<size>) >> dsl::p<size>) + dsl::p<binary_base> + dsl::p<binary_value>;
};

//
// Decimal number
//
// decimal_number ::=
//     unsigned_number
//   | [ size ] decimal_base unsigned_number
//   | [ size ] decimal_base x_digit { _ }
//   | [ size ] decimal_base z_digit { _ }
//
struct decimal_number
{
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule = []
    {
        const auto size_with_base =
            dsl::opt(dsl::peek(dsl::p<size>) >> dsl::p<size>) + dsl::p<decimal_base>;

        return dsl::peek(size_with_base) >> (size_with_base + (
                (_x >> dsl::while_(dsl::lit_c<'_'>)) |
                (_z >> dsl::while_(dsl::lit_c<'_'>)) |
                dsl::else_ >> dsl::p<unsigned_number>)) |
            dsl::else_ >> dsl::p<unsigned_number>;
    }();
};

//
// Integral number
//
// integral_number ::=
//     decimal_number
//   | octal_number
//   | binary_number
//   | hex_number
//
struct integral_number
{
    static constexpr auto rule =
        dsl::peek(dsl::p<decimal_number>) >> dsl::p<decimal_number> |
        dsl::peek(dsl::p<octal_number>) >> dsl::p<octal_number> |
        dsl::peek(dsl::p<binary_number>) >> dsl::p<binary_number> |
        dsl::peek(dsl::p<hex_number>) >> dsl::p<hex_number>;
};

//
// Number
//
// number ::=
//     integral_number
//   | real_number 
//
struct number
{
    static constexpr auto rule =
        dsl::peek(dsl::p<integral_number>) >> dsl::p<integral_number> |
        dsl::else_ >> dsl::p<real_number>;
};

}

#endif // SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
