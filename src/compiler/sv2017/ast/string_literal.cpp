// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/string_literal.h"

#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using StringLiteral = svs::sv2017::ast::StringLiteral;

StringLiteral::StringLiteral(const yy::location& location, std::string value)
    : Expression(location), value_(value) {}

void StringLiteral::Accept(Visitor& visitor) { visitor.Visit(*this); }
