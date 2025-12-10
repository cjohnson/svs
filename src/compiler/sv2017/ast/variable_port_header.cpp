// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/variable_port_header.h"

#include <memory>
#include <utility>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/port_direction.h"

using json = nlohmann::json;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

VariablePortHeader::VariablePortHeader(
    std::optional<PortDirection> port_direction,
    std::unique_ptr<ast::DataType> variable_port_type)
    : port_direction_(port_direction),
      variable_port_type_(std::move(variable_port_type)) {}

json VariablePortHeader::MarshallJson() {
  json j;

  if (port_direction_.has_value())
    j["port_direction"] = SerializePortDirection(port_direction_.value());
  j["variable_port_type"] = variable_port_type_->MarshallJson();

  return j;
}
