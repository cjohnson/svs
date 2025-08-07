#include "ast_visitor.h"

namespace ast = svs::ast::sv2017;

void ast::visitor_t::visit(const number_t &number)
{
    (void)number;
}

void ast::visitor_t::visit(const integral_number_t &integral_number)
{
    (void)integral_number;
}

void ast::visitor_t::visit(const real_number_t &real_number)
{
    (void)real_number;
}
