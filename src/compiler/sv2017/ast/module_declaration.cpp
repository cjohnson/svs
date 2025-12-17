// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_declaration.h"

#include <memory>
#include <utility>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using ModuleDeclaration = svs::sv2017::ast::ModuleDeclaration;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;
using TimeunitsDeclaration = svs::sv2017::ast::TimeunitsDeclaration;

ModuleDeclaration::ModuleDeclaration(
    const yy::location& location, std::unique_ptr<ModuleHeader> header,
    std::unique_ptr<TimeunitsDeclaration> timeunits_declaration)
    : Description(location),
      header_(std::move(header)),
      timeunits_declaration_(std::move(timeunits_declaration)) {}

void ModuleDeclaration::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::unique_ptr<ModuleHeader>& ModuleDeclaration::header() {
  return header_;
}

const std::unique_ptr<TimeunitsDeclaration>&
ModuleDeclaration::timeunits_declaration() {
  return timeunits_declaration_;
}
