// Copyright (c) 2025 Collin Johnson

#include "variable_port_header.h"

namespace ast = svs::sv2017::ast;

ast::VariablePortHeader::VariablePortHeader(
    std::optional<PortDirection> port_direction,
    std::unique_ptr<ast::DataType> variable_port_type)
  : port_direction_(port_direction),
    variable_port_type_(std::move(variable_port_type)) { }

std::string ast::VariablePortHeader::to_json(size_t indent_level) {
  return "";
}
