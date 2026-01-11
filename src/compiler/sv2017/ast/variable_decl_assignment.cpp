// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/variable_decl_assignment.h"

#include <memory>
#include <string>
#include <utility>

#include "compiler/sv2017/ast/visitor.h"

using VariableDeclAssignment = svs::sv2017::ast::VariableDeclAssignment;

VariableDeclAssignment::VariableDeclAssignment(
    const yy::location& location, std::string variable_identifier,
    std::unique_ptr<Expression> expression)
    : Node(location),
      variable_identifier_(std::move(variable_identifier)),
      expression_(std::move(expression)) {}

void VariableDeclAssignment::Accept(Visitor& visitor) { visitor.Visit(*this); }
