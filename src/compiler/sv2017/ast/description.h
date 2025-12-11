// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_DESCRIPTION_H_
#define SRC_COMPILER_SV2017_AST_DESCRIPTION_H_

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A SystemVerilog description element.
class Description : public Node {
 public:
  // Constructs a description element with the provided location.
  Description(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_DESCRIPTION_H_
