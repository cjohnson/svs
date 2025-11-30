// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_

#include "node.h"
#include "variable_port_header.h"

namespace svs::sv2017::ast {

// An ANSI-style port declaration.
class AnsiPortDeclaration : public Node {
 public:
  AnsiPortDeclaration(
    std::unique_ptr<VariablePortHeader> header,
    std::string identifier);

  std::string to_json(size_t indent_level = 0) override;

 private:
  // The port header
  std::unique_ptr<VariablePortHeader> header_;

  // The port identifier
  std::string identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
