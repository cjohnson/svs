// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/expression.h"

using Expression = svs::sv2017::ast::Expression;

Expression::Expression(const yy::location& location) : Node(location) {}
