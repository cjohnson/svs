#include "ast_number.h"

namespace ast = svs::ast::sv2017;

bool ast::operator==(const integral_number_t& lhs, const integral_number_t& rhs)
{
    return (lhs.size == rhs.size) &&
        (lhs.is_signed == rhs.is_signed) &&
        (lhs.value == rhs.value);
}
