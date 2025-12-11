// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/description.h"

#include "compiler/sv2017/location.hh"

using Description = svs::sv2017::ast::Description;

Description::Description(const yy::location& location) : Node(location) {}
