// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_
#define SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_

#include "data_type.h"
#include "integer_vector_type.h"

namespace svs::sv2017::ast {

// Integer vector data type
class IntegerVectorDataType : public DataType {
 public:
  // Constructs an integer vector data type.
  // Caller provides the type of integer vector.
  IntegerVectorDataType(const IntegerVectorType& type);

  // Returns a json representation of the tree.
  std::string to_json(size_t indent_level = 0) override;

 private:
  // The type of integer vector.
  IntegerVectorType type_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_
