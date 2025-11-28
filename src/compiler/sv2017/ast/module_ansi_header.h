// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
#define SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_

#include <memory>
#include <string>

#include "module_header.h"

namespace svs::sv2017::ast {

// An ANSI-style module header.
class ModuleAnsiHeader : public ModuleHeader {
 public:
  // Constructs an ANSI-style module header.
  // Client passes the module identifier.
  explicit ModuleAnsiHeader(const std::string& identifier);

  // Returns a json representation of the tree.
  std::string to_json(size_t indent_level = 0) override;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_ANSI_HEADER_H_
