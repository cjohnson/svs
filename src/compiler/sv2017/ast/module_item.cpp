// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/module_item.h"

using ModuleItem = svs::sv2017::ast::ModuleItem;

ModuleItem::ModuleItem(const yy::location& location) : Node(location) {}
