// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_header.h"

#include <string>

#include "compiler/sv2017/location.hh"

using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleHeader::ModuleHeader(const yy::location& location,
                           const std::string& identifier)
    : Node(location), identifier_(identifier) {}

const std::string& ModuleHeader::identifier() { return identifier_; }
