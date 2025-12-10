// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integer_vector_type.h"

#include <cassert>
#include <string>

using IntegerVectorType = svs::sv2017::ast::IntegerVectorType;
namespace ast = svs::sv2017::ast;

std::string ast::SerializeIntegerVectorType(
    const IntegerVectorType &integer_vector_type) {
  switch (integer_vector_type) {
    case IntegerVectorType::kBit:
      return "bit";
    case IntegerVectorType::kLogic:
      return "logic";
    case IntegerVectorType::kReg:
      return "reg";
  }
  assert(false && "Invalid integer vector type provided");
  return "";
}
