// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/attribute.h"

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/visitor.h"

using Attribute = svs::sv2017::ast::Attribute;

Attribute::Attribute(const yy::location& location, const std::string& name,
                     std::unique_ptr<Expression> value)
    : Node(location), name_(name), value_(std::move(value)) {}

void Attribute::Accept(Visitor& visitor) { visitor.Visit(*this); }
