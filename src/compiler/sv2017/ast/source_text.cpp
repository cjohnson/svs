// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/source_text.h"

#include <memory>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/module_declaration.h"

using json = nlohmann::json;
using SourceText = svs::sv2017::ast::SourceText;

SourceText::SourceText(
    std::vector<std::unique_ptr<ModuleDeclaration>> descriptions)
    : descriptions_(std::move(descriptions)) {}

json SourceText::MarshallJson() {
  json j;
  j["version"] = 2017;

  std::vector<json> descriptions_json;
  descriptions_json.reserve(descriptions_.size());
  for (const std::unique_ptr<ModuleDeclaration>& description : descriptions_)
    descriptions_json.emplace_back(description->MarshallJson());
  j["descriptions"] = descriptions_json;

  return j;
}
