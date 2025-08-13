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

ast::integral_number_t::integral_number_t(integral_number_type_t __type,
                                          std::optional<uint64_t> __size,
                                          bool __is_signed, std::string __value)
    : _type(__type), _size(__size), _is_signed(__is_signed), _value(__value)
{
}

void ast::integral_number_t::accept(visitor_t &visitor) const
{
    number_t::accept(visitor);
    visitor.visit(*this);
}

const ast::integral_number_type_t &ast::integral_number_t::
    integral_number_type() const
{
    return _type;
}

const std::optional<uint64_t> &ast::integral_number_t::size() const
{
    return _size;
}

bool ast::integral_number_t::is_signed() const
{
    return _is_signed;
}

const std::string &ast::integral_number_t::value() const
{
    return _value;
}

bool ast::operator==(const integral_number_t &lhs, const integral_number_t &rhs)
{
    return (lhs.integral_number_type() == rhs.integral_number_type()) &&
           (lhs.size() == rhs.size()) && (lhs.is_signed() == rhs.is_signed()) &&
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
