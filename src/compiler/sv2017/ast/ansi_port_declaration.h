// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/variable_port_header.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An ANSI-style port declaration.
class AnsiPortDeclaration : public Node {
 public:
  // Constructs an ANSI-style port declaration with the provided location,
  // header and identifier.
  AnsiPortDeclaration(const yy::location& location,
                      std::unique_ptr<VariablePortHeader> header,
                      std::string identifier);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The port header
  const std::unique_ptr<VariablePortHeader>& header();

  // The port identifier
  const std::string& identifier();

 private:
  std::unique_ptr<VariablePortHeader> header_;
  std::string identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_ANSI_PORT_DECLARATION_H_
