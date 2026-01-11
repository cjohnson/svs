// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_STATEMENT_H_
#define SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_STATEMENT_H_

#include <memory>

#include "compiler/sv2017/ast/statement.h"
#include "compiler/sv2017/ast/subroutine_call.h"

namespace svs::sv2017::ast {

// A subroutine call statement.
class SubroutineCallStatement : public Statement {
 public:
  // Constructs a subroutine call statement with the provided location and
  // subroutine call.
  SubroutineCallStatement(const yy::location& location,
                          std::unique_ptr<SubroutineCall> subroutine_call);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The subroutine call.
  inline const std::unique_ptr<SubroutineCall>& subroutine_call() {
    return subroutine_call_;
  }

 private:
  std::unique_ptr<SubroutineCall> subroutine_call_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SUBROUTINE_CALL_STATEMENT_H_
