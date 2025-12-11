// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_ansi_header.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/location.hh"

using json = nlohmann::json;

using ModuleAnsiHeader = svs::sv2017::ast::ModuleAnsiHeader;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleAnsiHeader::ModuleAnsiHeader(
    const yy::location& location, const std::string& identifier,
    std::vector<std::unique_ptr<AnsiPortDeclaration>> ports)
    : ModuleHeader(location, identifier), ports_(std::move(ports)) {}

json ModuleAnsiHeader::MarshallJson() {
  json j = ModuleHeader::MarshallJson();
  j["_type"] = "module_ansi_header";

  std::vector<json> ports_json;
  ports_json.reserve(ports_.size());
  for (const std::unique_ptr<AnsiPortDeclaration>& port : ports_)
    ports_json.emplace_back(port->MarshallJson());
  j["ports"] = ports_json;

  return j;
}
