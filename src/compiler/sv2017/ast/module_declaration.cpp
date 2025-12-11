// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_declaration.h"

#include <memory>
#include <utility>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/location.hh"

using json = nlohmann::json;
using ModuleDeclaration = svs::sv2017::ast::ModuleDeclaration;

ModuleDeclaration::ModuleDeclaration(const yy::location& location,
                                     std::unique_ptr<ModuleHeader> header)
    : Description(location), header_(std::move(header)) {}

json ModuleDeclaration::MarshallJson() {
  json j = Description::MarshallJson();
  j["_type"] = "module_declaration";

  j["header"] = header_->MarshallJson();

  return j;
}
