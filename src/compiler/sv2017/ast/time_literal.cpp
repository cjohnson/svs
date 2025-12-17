// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/time_literal.h"

#include <string>

#include "compiler/sv2017/ast/time_unit.h"
#include "compiler/sv2017/ast/visitor.h"

using TimeLiteral = svs::sv2017::ast::TimeLiteral;
using TimeUnit = svs::sv2017::ast::TimeUnit;

TimeLiteral::TimeLiteral(const yy::location& location, const std::string& value,
                         const TimeUnit& time_unit)
    : Node(location), value_(value), time_unit_(time_unit) {}

void TimeLiteral::Accept(Visitor& visitor) { visitor.Visit(*this); }

const TimeUnit& TimeLiteral::time_unit() { return time_unit_; }

const std::string& TimeLiteral::value() { return value_; }
