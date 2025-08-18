#include "ast.h"

namespace ast = svs::ast::sv2017;

ast::number_t::number_t()
{
}

ast::number_t::~number_t() = default;

void ast::number_t::accept(visitor_t &visitor) const
{
    visitor.visit(*this);
}

bool ast::operator==(const integral_number_base_info_t &lhs,
                     const integral_number_base_info_t &rhs)
{
    return lhs.signedness_indicator == rhs.signedness_indicator &&
           lhs.base_indicator == rhs.base_indicator;
}

ast::integral_number_t::integral_number_t(
    std::optional<std::string> __size,
    std::optional<integral_number_base_info_t> __base_info, std::string __value)
    : _size(__size), _base_info(__base_info), _value(__value)
{
}

void ast::integral_number_t::accept(visitor_t &visitor) const
{
    number_t::accept(visitor);
    visitor.visit(*this);
}

const std::optional<std::string> &ast::integral_number_t::size() const
{
    return _size;
}

const std::optional<ast::integral_number_base_info_t> &ast::integral_number_t::
    base_info() const
{
    return _base_info;
}

const std::string &ast::integral_number_t::value() const
{
    return _value;
}

bool ast::operator==(const integral_number_t &lhs, const integral_number_t &rhs)
{
    return (lhs.size() == rhs.size()) && (lhs.base_info() == rhs.base_info()) &&
           (lhs.value() == rhs.value());
}

bool ast::operator==(const fixed_point_number_info_t &lhs,
                     const fixed_point_number_info_t &rhs)
{
    return lhs.integer_part == rhs.integer_part &&
           lhs.fractional_part == rhs.fractional_part;
}

ast::real_number_t::real_number_t(std::string __integer_part,
                                  std::optional<std::string> __fractional_part,
                                  std::optional<std::string> __exponent)
    : _integer_part(__integer_part), _fractional_part(__fractional_part),
      _exponent(__exponent)
{
}

void ast::real_number_t::accept(visitor_t &visitor) const
{
    number_t::accept(visitor);
    visitor.visit(*this);
}

const std::string &ast::real_number_t::integer_part() const
{
    return _integer_part;
}

const std::optional<std::string> &ast::real_number_t::fractional_part() const
{
    return _fractional_part;
}

const std::optional<std::string> &ast::real_number_t::exponent() const
{
    return _exponent;
}

bool ast::operator==(const real_number_t &lhs, const real_number_t &rhs)
{
    return lhs.integer_part() == rhs.integer_part() &&
           lhs.fractional_part() == rhs.fractional_part() &&
           lhs.exponent() == rhs.exponent();
}

