// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_STATEMENT_H_
#define SRC_COMPILER_SV2017_AST_STATEMENT_H_

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A statement.
class Statement : public Node {
 public:
  // Constructs a statement with the provided location.
  explicit Statement(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_STATEMENT_H_
