// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/net_assignment.h"

#include <memory>
#include <string>
#include <utility>

#include "compiler/sv2017/ast/visitor.h"

using NetAssignment = svs::sv2017::ast::NetAssignment;

NetAssignment::NetAssignment(const yy::location& location,
                             const std::string& net_lvalue,
                             std::unique_ptr<Expression> expression)
    : Node(location),
      net_lvalue_(net_lvalue),
      expression_(std::move(expression)) {}

void NetAssignment::Accept(Visitor& visitor) { visitor.Visit(*this); }
