// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integer_vector_data_type.h"

using IntegerVectorDataType = svs::sv2017::ast::IntegerVectorDataType;

IntegerVectorDataType::IntegerVectorDataType(const IntegerVectorType& type)
    : type_(type) {}
