// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_VARIABLE_DECL_ASSIGNMENT_H_
#define SRC_COMPILER_SV2017_AST_VARIABLE_DECL_ASSIGNMENT_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/expression.h"
#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A variable declaration assignment.
class VariableDeclAssignment : public Node {
 public:
  // Constructs a variable declaration assignment from the provided location,
  // variable identifier, and expression.
  VariableDeclAssignment(const yy::location& location,
                         std::string variable_identifier,
                         std::unique_ptr<Expression> expression);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The variable identifier.
  inline const std::string& variable_identifier() {
    return variable_identifier_;
  }

  // The expression.
  inline const std::unique_ptr<Expression>& expression() { return expression_; }

 private:
  std::string variable_identifier_;
  std::unique_ptr<Expression> expression_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_VARIABLE_DECL_ASSIGNMENT_H_
