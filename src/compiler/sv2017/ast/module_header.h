// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_
#define SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_

#include <string>

#include "node.h"

namespace svs::sv2017::ast {

// A module header. Defines the public interface for the module.
class ModuleHeader : public Node {
 public:
  // Constructs a module header.
  // Client passes the module identifier.
  explicit ModuleHeader(const std::string& identifier);

 protected:
  // The identifier for the module.
  std::string identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_
