// Copyright (c) 2025 Collin Johnson

#include "node.h"

#include <ostream>

std::ostream& svs::sv2017::ast::Node::with_indent(
        std::ostream& os,
        size_t indent_level) {
    for (size_t i = 0; i < indent_level; ++i)
        os << "  ";
    return os;
}

