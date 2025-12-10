// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_

#include <memory>
#include <string>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/variable_port_header.h"

namespace svs::sv2017::ast {

// An ANSI-style port declaration.
class AnsiPortDeclaration : public Node {
 public:
  // Constructs an ANSI-style port declaration with the provided header
  // and identifier.
  AnsiPortDeclaration(std::unique_ptr<VariablePortHeader> header,
                      std::string identifier);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The port header
  std::unique_ptr<VariablePortHeader> header_;

  // The port identifier
  std::string identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
