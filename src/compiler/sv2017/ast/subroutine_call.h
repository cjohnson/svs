// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_H_
#define SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_H_

#include "compiler/sv2017/ast/node.h"

namespace svs::sv2017::ast {

// A subroutine call.
class SubroutineCall : public Node {
 public:
  // Constructs a subroutine call with the provided location.
  explicit SubroutineCall(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_H_
