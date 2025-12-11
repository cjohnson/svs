// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
#define SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_

#include <memory>
#include <vector>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// SystemVerilog 2017 source text AST node
class SourceText : public Node {
 public:
  // Constructs a source text with the provided location and descriptions
  SourceText(const yy::location& location,
             std::vector<std::unique_ptr<Description>> descriptions);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The list of descriptions
  std::vector<std::unique_ptr<Description>> descriptions_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
