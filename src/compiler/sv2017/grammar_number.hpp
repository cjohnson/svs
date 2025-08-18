#ifndef SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_

#include <memory>
#include <optional>
#include <string>

#include <lexy/callback.hpp>
#include <lexy/callback/fold.hpp>
#include <lexy/dsl.hpp>
#include <lexy/dsl/digit.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/grammar.hpp>
#include <sys/types.h>

#include "ast.h"

namespace svs::sv2017::grammar
{

namespace dsl = lexy::dsl;
namespace ast = svs::sv2017::ast;

//
// X (Unknown) digit
//
// x_digit ::= x | X
//
constexpr auto x_digit = dsl::lit_c<'x'> / dsl::lit_c<'X'>;

//
// Z (High-Impedance) digit
//
// z_digit ::= z | Z | ?
//
constexpr auto z_digit = dsl::lit_c<'z'> / dsl::lit_c<'Z'> / dsl::lit_c<'?'>;

//
// Z (High-Impedance) or X (Unknown) value
//
// z_or_x ::= x | X | z | Z
//
constexpr auto z_or_x =
    dsl::lit_c<'z'> / dsl::lit_c<'Z'> / dsl::lit_c<'x'> / dsl::lit_c<'X'>;

//
// Hex digit
//
// hex_digit ::= x_digit | z_digit
//               | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//               | a | b | c | d | e | f
//               | A | B | C | D | E | F
//
constexpr auto hex_digit = x_digit / z_digit / dsl::digit<dsl::hex>;

//
// Octal digit
//
// octal_digit ::= x_digit | z_digit | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7
//
constexpr auto octal_digit = x_digit / z_digit / dsl::digit<dsl::octal>;

//
// (B)inary dig(it)
//
// binary_digit ::= x_digit | z_digit | 0 | 1
//
constexpr auto binary_digit = x_digit / z_digit / dsl::digit<dsl::binary>;

//
// Exponent
//
// exp ::= e | E
//
constexpr auto exp_ = dsl::lit_c<'e'> / dsl::lit_c<'E'>;

//
// Sign
//
// sign ::= + | -
//
constexpr auto sign = dsl::lit_c<'+'> / dsl::lit_c<'-'>;

//
// Unbased, unsized literal
//
// unbased_unsized_literal ::= '0 | '1 | 'z_or_x
//
// Footnote 48:
// The apostrophe ( ' ) in unbased_unsized_literal shall not be followed by
// white_space.
//
struct unbased_unsized_literal
{
    static constexpr auto rule =
        dsl::lit_c<'\''> + dsl::capture(dsl::digit<dsl::binary> / z_or_x);
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
    static constexpr auto base_indicator = dsl::lit_c<'h'> / dsl::lit_c<'H'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> + (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >>
                                dsl::capture(base_indicator) |
                            dsl::capture(base_indicator));
    static constexpr auto value =
        lexy::callback<ast::integral_number_base_info_t>(
            [](auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    std::nullopt,
                    base_indicator_lexeme[0],
                };
            },
            [](auto signedness_indicator_lexeme, auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    signedness_indicator_lexeme[0],
                    base_indicator_lexeme[0],
                };
            });
};

//
// Octal base
//
// octal_base ::= '[s|S]o | '[s|S]O
//
struct octal_base
{
  private:
    static constexpr auto base_indicator = dsl::lit_c<'o'> / dsl::lit_c<'O'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> + (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >>
                                dsl::capture(base_indicator) |
                            dsl::capture(base_indicator));
    static constexpr auto value =
        lexy::callback<ast::integral_number_base_info_t>(
            [](auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    std::nullopt,
                    base_indicator_lexeme[0],
                };
            },
            [](auto signedness_indicator_lexeme, auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    signedness_indicator_lexeme[0],
                    base_indicator_lexeme[0],
                };
            });
};

//
// Binary base
//
// binary_base ::= '[s|S]b | '[s|S]B
//
struct binary_base
{
  private:
    static constexpr auto base_indicator = dsl::lit_c<'b'> / dsl::lit_c<'B'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> + (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >>
                                dsl::capture(base_indicator) |
                            dsl::capture(base_indicator));
    static constexpr auto value =
        lexy::callback<ast::integral_number_base_info_t>(
            [](auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    std::nullopt,
                    base_indicator_lexeme[0],
                };
            },
            [](auto signedness_indicator_lexeme, auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    signedness_indicator_lexeme[0],
                    base_indicator_lexeme[0],
                };
            });
};

//
// Decimal base
//
// decimal_base ::= '[s|S]d | '[s|S]D
//
struct decimal_base
{
  private:
    static constexpr auto base_indicator = dsl::lit_c<'d'> / dsl::lit_c<'D'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> + (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >>
                                dsl::capture(base_indicator) |
                            dsl::capture(base_indicator));
    static constexpr auto value =
        lexy::callback<ast::integral_number_base_info_t>(
            [](auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    std::nullopt,
                    base_indicator_lexeme[0],
                };
            },
            [](auto signedness_indicator_lexeme, auto base_indicator_lexeme) {
                return ast::integral_number_base_info_t{
                    signedness_indicator_lexeme[0],
                    base_indicator_lexeme[0],
                };
            });
};

//
// Hex value
//
// hex_value ::= hex_digit { _ | hex_digit }
//
struct hex_value
{
    static constexpr auto rule =
        dsl::identifier(hex_digit, hex_digit / dsl::digit_sep_underscore);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Octal value
//
// octal_value ::= octal_digit { _ | octal_digit }
//
struct octal_value
{
    static constexpr auto rule =
        dsl::identifier(octal_digit, octal_digit / dsl::digit_sep_underscore);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Binary value
//
// binary_value ::= binary_digit { _ | binary_digit }
//
struct binary_value
{
    static constexpr auto rule =
        dsl::identifier(binary_digit, binary_digit / dsl::digit_sep_underscore);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Unsigned number
//
// unsigned_number ::= decimal_digit { _ | decimal_digit }
//
struct unsigned_number
{
    static constexpr auto rule =
        dsl::identifier(dsl::digit<dsl::decimal>,
                        dsl::digit<dsl::decimal> / dsl::digit_sep_underscore);
    static constexpr auto value = lexy::as_string<std::string>;
};

//
// Fixed-point number
//
// fixed_point_number ::= unsigned_number . unsigned_number
//
struct fixed_point_number
{
    static constexpr auto rule =
        dsl::p<unsigned_number> + dsl::lit_c<'.'> + dsl::p<unsigned_number>;
    static constexpr auto value =
        lexy::callback<ast::fixed_point_number_info_t>(
            [](std::string integer_part, std::string fractional_part) {
                return ast::fixed_point_number_info_t{integer_part,
                                                      fractional_part};
            });
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
  private:
    struct sign_production
    {
        static constexpr auto rule = dsl::capture(sign);
        static constexpr auto value = lexy::as_string<std::string>;
    };

    struct real_number_with_exponent
    {
        static constexpr auto rule =
            dsl::p<unsigned_number> +
            dsl::opt(dsl::period >> dsl::p<unsigned_number>) + exp_ +
            dsl::opt(dsl::peek(sign) >> dsl::p<sign_production>) +
            dsl::p<unsigned_number>;
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::real_number_t>>(
                [](std::string integer_part,
                   std::optional<std::string> fractional_part,
                   std::optional<std::string> sign, std::string exponent) {
                    return std::make_shared<ast::real_number_t>(
                        integer_part, fractional_part,
                        sign.has_value() ? sign.value() + exponent : exponent);
                });
    };

  public:
    static constexpr auto rule =
        dsl::peek(dsl::p<real_number_with_exponent>) >>
            dsl::p<real_number_with_exponent> |
        dsl::peek(dsl::p<fixed_point_number>) >> dsl::p<fixed_point_number>;
    static constexpr auto value =
        lexy::callback<std::shared_ptr<ast::real_number_t>>(
            [](std::shared_ptr<ast::real_number_t> real_number) {
                return real_number;
            },
            [](ast::fixed_point_number_info_t fixed_point_number_info) {
                return std::make_shared<ast::real_number_t>(
                    fixed_point_number_info.integer_part,
                    fixed_point_number_info.fractional_part, std::nullopt);
            });
};

//
// Non-zero unsigned number
//
// non_zero_unsigned_number ::= non_zero_decimal_digit { _ | decimal_digit }
//
struct non_zero_unsigned_number
{
    static constexpr auto rule =
        dsl::identifier(dsl::digit<dsl::decimal> - dsl::zero,
                        dsl::digit<dsl::decimal> / dsl::digit_sep_underscore);
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
struct hex_number
{
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule =
        dsl::opt(dsl::p<size>) + dsl::p<hex_base> + dsl::p<hex_value>;
    static constexpr auto value =
        lexy::callback<std::shared_ptr<ast::integral_number_t>>(
            [](std::optional<std::string> size_string,
               ast::integral_number_base_info_t base_info, std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    size_string, base_info, value);
            });
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
        dsl::opt(dsl::p<size>) + dsl::p<octal_base> + dsl::p<octal_value>;
    static constexpr auto value =
        lexy::callback<std::shared_ptr<ast::integral_number_t>>(
            [](std::optional<std::string> size_string,
               ast::integral_number_base_info_t base_info, std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    size_string, base_info, value);
            });
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
        dsl::opt(dsl::p<size>) + dsl::p<binary_base> + dsl::p<binary_value>;
    static constexpr auto value =
        lexy::callback<std::shared_ptr<ast::integral_number_t>>(
            [](std::optional<std::string> size_string,
               ast::integral_number_base_info_t base_info, std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    size_string, base_info, value);
            });
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
  private:
    struct based_sized_unsigned_number
    {
        static constexpr auto whitespace = dsl::ascii::space;
        static constexpr auto rule = dsl::opt(dsl::p<size>) +
                                     dsl::p<decimal_base> +
                                     dsl::p<unsigned_number>;
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::integral_number_t>>(
                [](std::optional<std::string> size_string,
                   ast::integral_number_base_info_t base_info,
                   std::string value) {
                    return std::make_shared<ast::integral_number_t>(
                        size_string, base_info, value);
                });
    };

    struct based_sized_unknown_number
    {
        static constexpr auto whitespace = dsl::ascii::space;
        static constexpr auto rule =
            dsl::opt(dsl::p<size>) + dsl::p<decimal_base> +
            dsl::capture(x_digit) + dsl::while_(dsl::lit_c<'_'>);
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::integral_number_t>>(
                [](std::optional<std::string> size_string,
                   ast::integral_number_base_info_t base_info,
                   auto value_lexeme) {
                    return std::make_shared<ast::integral_number_t>(
                        size_string, base_info,
                        std::string(value_lexeme.begin(), value_lexeme.end()));
                });
    };

    struct based_sized_high_impedance_number
    {
        static constexpr auto whitespace = dsl::ascii::space;
        static constexpr auto rule =
            dsl::opt(dsl::p<size>) + dsl::p<decimal_base> +
            dsl::capture(z_digit) + dsl::while_(dsl::lit_c<'_'>);
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::integral_number_t>>(
                [](std::optional<std::string> size_string,
                   ast::integral_number_base_info_t base_info,
                   auto value_lexeme) {
                    return std::make_shared<ast::integral_number_t>(
                        size_string, base_info,
                        std::string(value_lexeme.begin(), value_lexeme.end()));
                });
    };

  public:
    static constexpr auto whitespace = dsl::ascii::space;
    static constexpr auto rule =
        dsl::peek(dsl::p<based_sized_unsigned_number>) >>
            dsl::p<based_sized_unsigned_number> |
        dsl::peek(dsl::p<based_sized_unknown_number>) >>
            dsl::p<based_sized_unknown_number> |
        dsl::peek(dsl::p<based_sized_high_impedance_number>) >>
            dsl::p<based_sized_high_impedance_number> |
        dsl::else_ >> dsl::p<unsigned_number>;
    static constexpr auto value =
        lexy::callback<std::shared_ptr<ast::integral_number_t>>(
            lexy::forward<std::shared_ptr<ast::integral_number_t>>,
            [](std::string unsigned_value) {
                return std::make_shared<ast::integral_number_t>(
                    std::nullopt, std::nullopt, unsigned_value);
            });
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
        dsl::peek(dsl::p<octal_number>) >> dsl::p<octal_number> |
        dsl::peek(dsl::p<binary_number>) >> dsl::p<binary_number> |
        dsl::peek(dsl::p<hex_number>) >> dsl::p<hex_number> |
        dsl::peek(dsl::p<decimal_number>) >> dsl::p<decimal_number>;
    static constexpr auto value =
        lexy::forward<std::shared_ptr<ast::integral_number_t>>;
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
        dsl::peek(dsl::p<real_number>) >> dsl::p<real_number> |
        dsl::peek(dsl::p<integral_number>) >> dsl::p<integral_number>;
    static constexpr auto value = lexy::forward<std::shared_ptr<ast::number_t>>;
};

} // namespace svs::sv2017::grammar

#endif // SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
