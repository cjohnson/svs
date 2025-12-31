// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_EXPRESSION_H_
#define SRC_COMPILER_SV2017_AST_EXPRESSION_H_

#include "compiler/sv2017/ast/node.h"

namespace svs::sv2017::ast {

class Expression : public Node {
 public:
  // Constructs an expression with the provided location.
  explicit Expression(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_EXPRESSION_H_
