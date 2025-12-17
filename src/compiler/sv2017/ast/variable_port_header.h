// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_VARIABLE_PORT_HEADER_H_
#define SRC_COMPILER_SV2017_AST_VARIABLE_PORT_HEADER_H_

#include <memory>
#include <optional>

#include "compiler/sv2017/ast/data_type.h"
#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/port_direction.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// Header for a variable port.
class VariablePortHeader : public Node {
 public:
  // Constructs a variable port header.
  //
  // Caller provides the port direction (if applicable)
  // and the port type.
  VariablePortHeader(const yy::location& location,
                     std::optional<PortDirection> port_direction,
                     std::unique_ptr<DataType> variable_port_type);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The port direction.
  // Has a value if the designer provided a direction.
  const std::optional<PortDirection>& port_direction();

  // The port type.
  const std::unique_ptr<DataType>& variable_port_type();

 private:
  std::optional<PortDirection> port_direction_;
  std::unique_ptr<DataType> variable_port_type_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_VARIABLE_PORT_HEADER_H_
