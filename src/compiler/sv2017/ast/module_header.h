// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_
#define SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_

#include <string>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A module header. Defines the public interface for the module.
class ModuleHeader : public Node {
 public:
  // Constructs a module header.
  // Client passes the module identifier.
  ModuleHeader(const yy::location& location, const std::string& identifier);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 protected:
  // The identifier for the module.
  std::string identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_HEADER_H_
