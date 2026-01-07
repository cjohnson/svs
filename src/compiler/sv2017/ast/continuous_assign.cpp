// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/continuous_assign.h"

#include <utility>
#include <vector>

#include "compiler/sv2017/ast/visitor.h"

using ContinuousAssign = svs::sv2017::ast::ContinuousAssign;

ContinuousAssign::ContinuousAssign(
    const yy::location& location,
    std::vector<std::unique_ptr<NetAssignment>> net_assignments)
    : ModuleItem(location), net_assignments_(std::move(net_assignments)) {}

void ContinuousAssign::Accept(Visitor& visitor) { visitor.Visit(*this); }
