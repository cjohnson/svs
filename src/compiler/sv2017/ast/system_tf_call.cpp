// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/system_tf_call.h"

#include <string>

#include "compiler/sv2017/ast/subroutine_call.h"
#include "compiler/sv2017/ast/visitor.h"

using SystemTfCall = svs::sv2017::ast::SystemTfCall;

SystemTfCall::SystemTfCall(const yy::location& location,
                           std::string system_tf_identifier)
    : SubroutineCall(location), system_tf_identifier_(system_tf_identifier) {}

void SystemTfCall::Accept(Visitor& visitor) { visitor.Visit(*this); }
