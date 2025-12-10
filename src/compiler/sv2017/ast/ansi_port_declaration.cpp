// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/ansi_port_declaration.h"

#include <memory>
#include <string>
#include <utility>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using AnsiPortDeclaration = svs::sv2017::ast::AnsiPortDeclaration;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

AnsiPortDeclaration::AnsiPortDeclaration(
    std::unique_ptr<VariablePortHeader> header, std::string identifier)
    : header_(std::move(header)), identifier_(std::move(identifier)) {}

json AnsiPortDeclaration::MarshallJson() {
  json j;
  j["header"] = header_->MarshallJson();
  j["identifier"] = identifier_;

  return j;
}
