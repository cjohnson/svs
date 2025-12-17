// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/json/serializer.h"

#include <string>

#include "compiler/sv2017/json/visitor.h"

using Serializer = svs::sv2017::json::Serializer;

std::string Serializer::Serialize(ast::SourceText& source_text) {
  Visitor visitor;
  nlohmann::json json = visitor.Serialize(source_text);

  return json.dump(2);
}
