// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_BLOCKING_ASSIGNMENT_H_
#define SRC_COMPILER_SV2017_AST_BLOCKING_ASSIGNMENT_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/expression.h"
#include "compiler/sv2017/ast/statement.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A blocking assignment.
class BlockingAssignment : public Statement {
 public:
  // Constructs a blocking assignment using the provided location, variable
  // lvalue, and expression.
  BlockingAssignment(const yy::location& location, std::string variable_lvalue,
                     std::unique_ptr<Expression> expression);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The variable lvalue.
  inline const std::string& variable_lvalue() { return variable_lvalue_; }

  // The expression.
  inline const std::unique_ptr<Expression>& expression() { return expression_; }

 private:
  std::string variable_lvalue_;
  std::unique_ptr<Expression> expression_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_BLOCKING_ASSIGNMENT_H_
