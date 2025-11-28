// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
#define SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_

#include <memory>
#include <string>
#include <vector>

#include "ast.h"
#include "module_declaration.h"

namespace svs::sv2017::ast {

// SystemVerilog 2017 source text AST node
class SourceText : public Node {
 public:
  // Returns a json representation of the tree.
  std::string to_json(size_t indent_level = 0) override;

 private:
  std::vector<std::unique_ptr<ModuleDeclaration>> descriptions_;

  friend yy::parser;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
