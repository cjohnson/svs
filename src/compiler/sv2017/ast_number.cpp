#include "ast_number.h"

namespace ast = svs::ast::sv2017;

bool ast::operator==(const IntegerLiteralConstant& lhs, const IntegerLiteralConstant& rhs)
{
    return (lhs.size == rhs.size) &&
        (lhs.is_signed == rhs.is_signed) &&
        (lhs.bits == rhs.bits);
}
