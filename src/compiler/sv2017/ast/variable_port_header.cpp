// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/variable_port_header.h"

#include <memory>
#include <nlohmann/json.hpp>
#include <utility>

#include "compiler/sv2017/ast/port_direction.h"
#include "compiler/sv2017/ast/visitor.h"

using json = nlohmann::json;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

VariablePortHeader::VariablePortHeader(
    const yy::location& location, std::optional<PortDirection> port_direction,
    std::unique_ptr<ast::DataType> variable_port_type)
    : Node(location),
      port_direction_(port_direction),
      variable_port_type_(std::move(variable_port_type)) {}

void VariablePortHeader::Accept(Visitor& visitor) { visitor.Visit(*this); }

json VariablePortHeader::MarshallJson() {
  json j = Node::MarshallJson();
  j["_type"] = "variable_port_header";

  if (port_direction_.has_value())
    j["port_direction"] = SerializePortDirection(port_direction_.value());
  j["variable_port_type"] = variable_port_type_->MarshallJson();

  return j;
}
