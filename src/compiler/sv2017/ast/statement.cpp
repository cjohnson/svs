// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/statement.h"

using Statement = svs::sv2017::ast::Statement;

Statement::Statement(const yy::location& location) : Node(location) {}
