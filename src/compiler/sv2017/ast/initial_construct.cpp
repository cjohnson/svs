// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/initial_construct.h"

#include <memory>
#include <utility>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/visitor.h"

using InitialConstruct = svs::sv2017::ast::InitialConstruct;

InitialConstruct::InitialConstruct(const yy::location& location,
                                   std::unique_ptr<Statement> statement)
    : ModuleItem(location), statement_(std::move(statement)) {}

void InitialConstruct::Accept(Visitor& visitor) { visitor.Visit(*this); }
