// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/ansi_port_declaration.h"

#include <memory>
#include <string>
#include <utility>

#include "compiler/sv2017/ast/visitor.h"

using AnsiPortDeclaration = svs::sv2017::ast::AnsiPortDeclaration;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

AnsiPortDeclaration::AnsiPortDeclaration(
    const yy::location& location,
    std::unique_ptr<VariablePortHeader> header, std::string identifier)
    : Node(location),
      header_(std::move(header)),
      identifier_(std::move(identifier)) {}

void AnsiPortDeclaration::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::unique_ptr<VariablePortHeader>& AnsiPortDeclaration::header() {
  return header_;
}

const std::string& AnsiPortDeclaration::identifier() { return identifier_; }
