// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/ansi_port_declaration.h"

#include <memory>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/visitor.h"

using json = nlohmann::json;
using AnsiPortDeclaration = svs::sv2017::ast::AnsiPortDeclaration;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

AnsiPortDeclaration::AnsiPortDeclaration(
    const yy::location& location, std::unique_ptr<VariablePortHeader> header,
    std::string identifier)
    : Node(location),
      header_(std::move(header)),
      identifier_(std::move(identifier)) {}

void AnsiPortDeclaration::Accept(Visitor& visitor) { visitor.Visit(*this); }

json AnsiPortDeclaration::MarshallJson() {
  json j = Node::MarshallJson();
  j["_type"] = "ansi_port_declaration";

  j["header"] = header_->MarshallJson();
  j["identifier"] = identifier_;

  return j;
}
