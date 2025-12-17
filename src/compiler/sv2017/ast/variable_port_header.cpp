// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/variable_port_header.h"

#include <memory>
#include <utility>

#include "compiler/sv2017/ast/data_type.h"
#include "compiler/sv2017/ast/port_direction.h"
#include "compiler/sv2017/ast/visitor.h"

using DataType = svs::sv2017::ast::DataType;
using PortDirection = svs::sv2017::ast::PortDirection;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

VariablePortHeader::VariablePortHeader(
    const yy::location& location, std::optional<PortDirection> port_direction,
    std::unique_ptr<ast::DataType> variable_port_type)
    : Node(location),
      port_direction_(port_direction),
      variable_port_type_(std::move(variable_port_type)) {}

void VariablePortHeader::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::optional<PortDirection>& VariablePortHeader::port_direction() {
  return port_direction_;
}

const std::unique_ptr<DataType>& VariablePortHeader::variable_port_type() {
  return variable_port_type_;
}
