// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_NET_ASSIGNMENT_H_
#define SRC_COMPILER_SV2017_AST_NET_ASSIGNMENT_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/expression.h"
#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A net assignment.
class NetAssignment : public Node {
 public:
  // Construcst a net assignment with the provided location, net lvalue, and
  // expression.
  NetAssignment(const yy::location& location, const std::string& net_lvalue,
                std::unique_ptr<Expression> expression);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The net's lvalue.
  inline const std::string& net_lvalue() { return net_lvalue_; }

  // The expression assigned to the net.
  inline const std::unique_ptr<Expression>& expression() { return expression_; }

 private:
  std::string net_lvalue_;
  std::unique_ptr<Expression> expression_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_NET_ASSIGNMENT_H_
