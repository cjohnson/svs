// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/subroutine_call_statement.h"

#include <memory>
#include <utility>

#include "compiler/sv2017/ast/visitor.h"

using SubroutineCallStatement = svs::sv2017::ast::SubroutineCallStatement;

SubroutineCallStatement::SubroutineCallStatement(
    const yy::location& location,
    std::unique_ptr<SubroutineCall> subroutine_call)
    : Statement(location), subroutine_call_(std::move(subroutine_call)) {}

void SubroutineCallStatement::Accept(Visitor& visitor) { visitor.Visit(*this); }
