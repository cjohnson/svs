// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integer_vector_data_type.h"

#include "compiler/sv2017/ast/integer_vector_type.h"
#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using IntegerVectorType = svs::sv2017::ast::IntegerVectorType;
using IntegerVectorDataType = svs::sv2017::ast::IntegerVectorDataType;

IntegerVectorDataType::IntegerVectorDataType(
    const yy::location& location, const IntegerVectorType& integer_vector_type)
    : DataType(location), integer_vector_type_(integer_vector_type) {}

void IntegerVectorDataType::Accept(Visitor& visitor) { visitor.Visit(*this); }

const IntegerVectorType& IntegerVectorDataType::integer_vector_type() {
  return integer_vector_type_;
}
