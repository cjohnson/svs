// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
#define SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_

#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An ANSI-style module header.
class ModuleAnsiHeader : public ModuleHeader {
 public:
  // Constructs an ANSI-style module header.
  // Client passes the module identifier and module ports.
  ModuleAnsiHeader(const yy::location& location, const std::string& identifier,
                   std::vector<std::unique_ptr<AnsiPortDeclaration>> ports);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The module ports
  std::vector<std::unique_ptr<AnsiPortDeclaration>> ports_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
