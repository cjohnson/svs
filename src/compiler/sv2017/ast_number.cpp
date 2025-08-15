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
    std::optional<std::string> __signedness_indicator,
    std::string __base_indicator, std::string __value)
    : _size(__size), _signedness_indicator(__signedness_indicator),
      _base_indicator(__base_indicator), _value(__value)
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

const std::optional<std::string> &ast::integral_number_t::signedness_indicator()
    const
{
    return _signedness_indicator;
}

const std::optional<std::string> &ast::integral_number_t::base_indicator() const
{
    return _base_indicator;
}

const std::string &ast::integral_number_t::value() const
{
    return _value;
}

bool ast::operator==(const integral_number_t &lhs, const integral_number_t &rhs)
{
    return (lhs.size() == rhs.size()) &&
           (lhs.signedness_indicator() == rhs.signedness_indicator()) &&
           (lhs.base_indicator() == rhs.base_indicator()) &&
           (lhs.value() == rhs.value());
}

ast::real_number_t::real_number_t(double __value) : _value(__value)
{
}

void ast::real_number_t::accept(visitor_t &visitor) const
{
    number_t::accept(visitor);
    visitor.visit(*this);
}

double ast::real_number_t::value() const
{
    return _value;
}

bool ast::operator==(const real_number_t &lhs, const real_number_t &rhs)
{
    return lhs.value() == rhs.value();
}
