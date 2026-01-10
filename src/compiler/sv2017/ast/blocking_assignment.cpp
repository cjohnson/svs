// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/blocking_assignment.h"

#include <memory>
#include <string>
#include <utility>

#include "compiler/sv2017/ast/visitor.h"

using BlockingAssignment = svs::sv2017::ast::BlockingAssignment;

BlockingAssignment::BlockingAssignment(const yy::location& location,
                                       std::string variable_lvalue,
                                       std::unique_ptr<Expression> expression)
    : Statement(location),
      variable_lvalue_(variable_lvalue),
      expression_(std::move(expression)) {}

void BlockingAssignment::Accept(Visitor& visitor) { visitor.Visit(*this); }
