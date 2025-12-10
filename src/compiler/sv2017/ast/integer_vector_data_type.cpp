// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integer_vector_data_type.h"

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/integer_vector_type.h"

using json = nlohmann::json;
using IntegerVectorDataType = svs::sv2017::ast::IntegerVectorDataType;

IntegerVectorDataType::IntegerVectorDataType(const IntegerVectorType& type)
    : type_(type) {}

json IntegerVectorDataType::MarshallJson() {
  json j;
  j["type"] = SerializeIntegerVectorType(type_);

  return j;
}
