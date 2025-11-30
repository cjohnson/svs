// Copyright (c) 2025 Collin Johnson

#include "integer_vector_data_type.h"

namespace ast = svs::sv2017::ast;

ast::IntegerVectorDataType::IntegerVectorDataType(const IntegerVectorType& type)
  : type_(type) { }

std::string ast::IntegerVectorDataType::to_json(size_t indent_level) {
  return "";
}
