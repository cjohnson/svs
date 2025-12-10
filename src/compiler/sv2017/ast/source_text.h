// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
#define SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_

#include <memory>
#include <vector>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/module_declaration.h"

namespace svs::sv2017::ast {

// SystemVerilog 2017 source text AST node
class SourceText : public Node {
 public:
  // Constructs a source text with the provided descriptions
  explicit SourceText(
      std::vector<std::unique_ptr<ModuleDeclaration>> descriptions);

  // Returns the JSON representation of the tree.
  virtual json MarshallJson();

 private:
  // The list of descriptions
  std::vector<std::unique_ptr<ModuleDeclaration>> descriptions_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
