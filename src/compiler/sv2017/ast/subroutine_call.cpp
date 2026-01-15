// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/subroutine_call.h"

#include <utility>
#include <vector>

#include "compiler/sv2017/location.hh"

using SubroutineCall = svs::sv2017::ast::SubroutineCall;

SubroutineCall::SubroutineCall(
    const yy::location& location,
    std::vector<std::unique_ptr<Expression>> arguments)
    : Node(location), arguments_(std::move(arguments)) {}
