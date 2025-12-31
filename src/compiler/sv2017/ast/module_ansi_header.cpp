// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_ansi_header.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using Attribute = svs::sv2017::ast::Attribute;
using AnsiPortDeclaration = svs::sv2017::ast::AnsiPortDeclaration;
using Lifetime = svs::sv2017::ast::Lifetime;
using ModuleAnsiHeader = svs::sv2017::ast::ModuleAnsiHeader;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleAnsiHeader::ModuleAnsiHeader(
    const yy::location& location,
    std::vector<std::unique_ptr<Attribute>> attributes,
    const std::optional<Lifetime>& lifetime, const std::string& identifier,
    std::vector<std::unique_ptr<AnsiPortDeclaration>> ports)
    : ModuleHeader(location, identifier),
      attributes_(std::move(attributes)),
      lifetime_(lifetime),
      ports_(std::move(ports)) {}

void ModuleAnsiHeader::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::vector<std::unique_ptr<Attribute>>& ModuleAnsiHeader::attributes() {
  return attributes_;
}

const std::optional<Lifetime>& ModuleAnsiHeader::lifetime() {
  return lifetime_;
}

const std::vector<std::unique_ptr<AnsiPortDeclaration>>&
ModuleAnsiHeader::ports() {
  return ports_;
}
