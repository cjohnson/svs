// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_JSON_SERIALIZER_H_
#define SRC_COMPILER_SV2017_JSON_SERIALIZER_H_

#include <string>

#include "compiler/sv2017/ast/source_text.h"

namespace svs::sv2017::json {

// Serializes an AST into JSON.
class Serializer {
 public:
  // Serializes an AST into JSON.
  std::string Serialize(ast::SourceText& source_text);
};

}  // namespace svs::sv2017::json

#endif  // SRC_COMPILER_SV2017_JSON_SERIALIZER_H_
