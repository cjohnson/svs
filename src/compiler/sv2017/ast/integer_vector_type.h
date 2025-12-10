// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_
#define SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_

#include <string>

namespace svs::sv2017::ast {

// The type of integer vector
enum class IntegerVectorType {
  // A bit integer vector.
  kBit,

  // A logic integer vector.
  kLogic,

  // A reg integer vector.
  kReg,
};

// Returns the serialized form of the provided integer vector type
std::string SerializeIntegerVectorType(
    const IntegerVectorType& integer_vector_type);

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_
