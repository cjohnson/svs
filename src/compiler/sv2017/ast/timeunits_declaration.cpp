// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/timeunits_declaration.h"

#include <memory>
#include <utility>

#include "compiler/sv2017/ast/time_literal.h"
#include "compiler/sv2017/ast/visitor.h"

using TimeLiteral = svs::sv2017::ast::TimeLiteral;
using TimeunitsDeclaration = svs::sv2017::ast::TimeunitsDeclaration;

TimeunitsDeclaration::TimeunitsDeclaration(
    const yy::location& location, std::unique_ptr<TimeLiteral> time_unit,
    std::unique_ptr<TimeLiteral> time_precision)
    : Node(location),
      time_unit_(std::move(time_unit)),
      time_precision_(std::move(time_precision)) {}

void TimeunitsDeclaration::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::unique_ptr<TimeLiteral>& TimeunitsDeclaration::time_unit() {
  return time_unit_;
}

const std::unique_ptr<TimeLiteral>& TimeunitsDeclaration::time_precision() {
  return time_precision_;
}
