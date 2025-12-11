// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/data_type.h"

#include "compiler/sv2017/location.hh"

using DataType = svs::sv2017::ast::DataType;

DataType::DataType(const yy::location& location) : Node(location) {}
