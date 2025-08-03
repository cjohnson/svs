#ifndef SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
#define SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_

#include <memory>
#include <optional>
#include <sstream>
#include <string>

#include <lexy/callback.hpp>
#include <lexy/callback/fold.hpp>
#include <lexy/dsl.hpp>
#include <lexy/dsl/digit.hpp>
#include <lexy/dsl/identifier.hpp>
#include <lexy/grammar.hpp>
#include <sys/types.h>

#include "ast_number.h"

namespace svs::grammar::sv2017
{

namespace dsl = lexy::dsl;
namespace ast = svs::ast::sv2017;

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
constexpr auto exp = dsl::lit_c<'e'> / dsl::lit_c<'E'>;

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
    static constexpr auto indicator = dsl::lit_c<'h'> / dsl::lit_c<'H'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> +
        (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >> indicator |
         indicator);
    static constexpr auto value = lexy::callback<bool>([]() { return false; },
                                                       [](auto _) {
                                                           (void)_;
                                                           return true;
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
    static constexpr auto indicator = dsl::lit_c<'o'> / dsl::lit_c<'O'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> +
        (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >> indicator |
         indicator);
    static constexpr auto value = lexy::callback<bool>([]() { return false; },
                                                       [](auto _) {
                                                           (void)_;
                                                           return true;
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
    static constexpr auto indicator = dsl::lit_c<'b'> / dsl::lit_c<'B'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> +
        (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >> indicator |
         indicator);
    static constexpr auto value = lexy::callback<bool>([]() { return false; },
                                                       [](auto _) {
                                                           (void)_;
                                                           return true;
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
    static constexpr auto indicator = dsl::lit_c<'d'> / dsl::lit_c<'D'>;

  public:
    static constexpr auto rule =
        dsl::lit_c<'\''> +
        (dsl::capture(dsl::lit_c<'s'> / dsl::lit_c<'S'>) >> indicator |
         indicator);
    static constexpr auto value = lexy::callback<bool>([]() { return false; },
                                                       [](auto _) {
                                                           (void)_;
                                                           return true;
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
    static constexpr auto value = lexy::callback<std::string>(
        [](std::string integer_part, std::string fractional_part) {
            return integer_part + "." + fractional_part;
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
    static constexpr auto rule =
        dsl::p<unsigned_number> +
        dsl::opt(dsl::period >> dsl::p<unsigned_number>) +
        dsl::if_(exp >> (dsl::opt(sign) + dsl::p<unsigned_number>));
    static constexpr auto value = lexy::callback<std::string>(
        [](std::string integer_part,
           std::optional<std::string> fractional_part) {
            std::stringstream ss;
            ss << integer_part;
            if (fractional_part.has_value())
            {
                ss << '.';
                ss << fractional_part.value();
            }
            return ss.str();
        },
        [](std::string integer_part, std::optional<std::string> fractional_part,
           std::optional<std::string> sign, std::string exponent_part) {
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

    //
    // Converts the result of the parsing operation to a uint64_t.
    //
    static uint64_t to_uint64_t(std::string value)
    {
        std::string without_underscores;
        for (const char &c : value)
        {
            without_underscores += c;
        }
        return (uint64_t)std::stoull(without_underscores);
    }
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
            [](std::optional<std::string> size_string, bool is_signed,
               std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    ast::integral_number_type_t::Hexadecimal,
                    size_string.has_value()
                        ? (std::optional<uint64_t>)size::to_uint64_t(
                              size_string.value())
                        : (std::optional<uint64_t>)std::nullopt,
                    is_signed, value);
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
            [](std::optional<std::string> size_string, bool is_signed,
               std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    ast::integral_number_type_t::Octal,
                    size_string.has_value()
                        ? (std::optional<uint64_t>)size::to_uint64_t(
                              size_string.value())
                        : (std::optional<uint64_t>)std::nullopt,
                    is_signed, value);
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
            [](std::optional<std::string> size_string, bool is_signed,
               std::string value) {
                return std::make_shared<ast::integral_number_t>(
                    ast::integral_number_type_t::Binary,
                    size_string.has_value()
                        ? (std::optional<uint64_t>)size::to_uint64_t(
                              size_string.value())
                        : (std::optional<uint64_t>)std::nullopt,
                    is_signed, value);
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
                [](std::optional<std::string> size_string, bool is_signed,
                   std::string value) {
                    return std::make_shared<ast::integral_number_t>(
                        ast::integral_number_type_t::Decimal,
                        size_string.has_value()
                            ? (std::optional<uint64_t>)size::to_uint64_t(
                                  size_string.value())
                            : (std::optional<uint64_t>)std::nullopt,
                        is_signed, value);
                });
    };

    struct based_sized_unknown_number
    {
        static constexpr auto whitespace = dsl::ascii::space;
        static constexpr auto rule = dsl::opt(dsl::p<size>) +
                                     dsl::p<decimal_base> + x_digit +
                                     dsl::while_(dsl::lit_c<'_'>);
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::integral_number_t>>(
                [](std::optional<std::string> size_string, bool is_signed) {
                    return std::make_shared<ast::integral_number_t>(
                        ast::integral_number_type_t::Decimal,
                        size_string.has_value()
                            ? (std::optional<uint64_t>)size::to_uint64_t(
                                  size_string.value())
                            : (std::optional<uint64_t>)std::nullopt,
                        is_signed, "X");
                });
    };

    struct based_sized_high_impedance_number
    {
        static constexpr auto whitespace = dsl::ascii::space;
        static constexpr auto rule = dsl::opt(dsl::p<size>) +
                                     dsl::p<decimal_base> + z_digit +
                                     dsl::while_(dsl::lit_c<'_'>);
        static constexpr auto value =
            lexy::callback<std::shared_ptr<ast::integral_number_t>>(
                [](std::optional<std::string> size_string, bool is_signed) {
                    return std::make_shared<ast::integral_number_t>(
                        ast::integral_number_type_t::Decimal,
                        size_string.has_value()
                            ? (std::optional<uint64_t>)size::to_uint64_t(
                                  size_string.value())
                            : (std::optional<uint64_t>)std::nullopt,
                        is_signed, "Z");
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
                    ast::integral_number_type_t::Decimal, std::nullopt,
                    true, // The value specified matching the unsigned value
                          // rule is actually a signed value
                    unsigned_value);
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
        dsl::peek(dsl::p<integral_number>) >> dsl::p<integral_number>; //|
    // dsl::else_ >> dsl::p<real_number>;
    // static constexpr auto value = lexy::new_<ast::number_t,
    // std::shared_ptr<ast::number_t>>;
    static constexpr auto value = lexy::forward<std::shared_ptr<ast::number_t>>;
};

} // namespace svs::grammar::sv2017

#endif // SVS_COMPILER_SV2017_GRAMMAR_NUMBER_H_
