// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_declaration.h"

#include <memory>
#include <utility>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using ModuleDeclaration = svs::sv2017::ast::ModuleDeclaration;

ModuleDeclaration::ModuleDeclaration(std::unique_ptr<ModuleHeader> header)
    : header_(std::move(header)) {}

json ModuleDeclaration::MarshallJson() {
  json j;
  j["declaration_type"] = "module";
  j["header"] = header_->MarshallJson();

  return j;
}
