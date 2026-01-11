// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/subroutine_call.h"

#include "compiler/sv2017/location.hh"

using SubroutineCall = svs::sv2017::ast::SubroutineCall;

SubroutineCall::SubroutineCall(const yy::location& location) : Node(location) {}
