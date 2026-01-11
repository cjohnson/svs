// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/data_declaration.h"

#include <memory>
#include <utility>
#include <vector>

#include "compiler/sv2017/ast/visitor.h"

using DataDeclaration = svs::sv2017::ast::DataDeclaration;

DataDeclaration::DataDeclaration(
    const yy::location& location, std::unique_ptr<DataType> data_type,
    std::vector<std::unique_ptr<VariableDeclAssignment>>
        variable_decl_assignments)
    : ModuleItem(location),
      data_type_(std::move(data_type)),
      variable_decl_assignments_(std::move(variable_decl_assignments)) {}

void DataDeclaration::Accept(Visitor& visitor) { visitor.Visit(*this); }
