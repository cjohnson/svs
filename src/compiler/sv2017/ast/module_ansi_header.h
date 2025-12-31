// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
#define SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_

#include <memory>
#include <string>
#include <vector>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/attribute.h"
#include "compiler/sv2017/ast/lifetime.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An ANSI-style module header.
class ModuleAnsiHeader : public ModuleHeader {
 public:
  // Constructs an ANSI-style module header.
  // Client passes the module identifier and module ports.
  ModuleAnsiHeader(const yy::location& location,
                   std::vector<std::unique_ptr<Attribute>> attributes,
                   const std::optional<Lifetime>& lifetime,
                   const std::string& identifier,
                   std::vector<std::unique_ptr<AnsiPortDeclaration>> ports);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The attributes for the module.
  const std::vector<std::unique_ptr<Attribute>>& attributes();

  // The lifetime of the module
  const std::optional<Lifetime>& lifetime();

  // The module ports
  const std::vector<std::unique_ptr<AnsiPortDeclaration>>& ports();

 private:
  std::vector<std::unique_ptr<Attribute>> attributes_;
  std::optional<Lifetime> lifetime_;
  std::vector<std::unique_ptr<AnsiPortDeclaration>> ports_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
