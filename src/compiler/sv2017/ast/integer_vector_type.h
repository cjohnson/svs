// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_
#define SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_

namespace svs::sv2017::ast {

// The type of integer vector
enum class IntegerVectorType {
  kBit,
  kLogic,
  kReg,
};

}

#endif  // SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_TYPE_H_
