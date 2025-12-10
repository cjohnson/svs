// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integer_vector_data_type.h"

#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using IntegerVectorDataType = svs::sv2017::ast::IntegerVectorDataType;

IntegerVectorDataType::IntegerVectorDataType(const IntegerVectorType& type)
    : type_(type) {}

json IntegerVectorDataType::MarshallJson() {
  json j;

  std::string type_serialized;
  switch (type_) {
    case IntegerVectorType::kBit:
      type_serialized = "bit";
      break;
    case IntegerVectorType::kLogic:
      type_serialized = "logic";
      break;
    case IntegerVectorType::kReg:
      type_serialized = "reg";
      break;
  }
  j["type"] = type_serialized;

  return j;
}
