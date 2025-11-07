#include <ostream>

#include "ast.h"

using namespace svs::sv2017;

std::ostream& ast::node_t::with_indent(
        std::ostream& os,
        size_t indent_level) {
    for (size_t i = 0; i < indent_level; ++i)
        os << "  ";
    return os;
}

