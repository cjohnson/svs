// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_
#define SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/data_type.h"
#include "compiler/sv2017/ast/integer_vector_type.h"

namespace svs::sv2017::ast {

// Integer vector data type
class IntegerVectorDataType : public DataType {
 public:
  // Constructs an integer vector data type.
  // Caller provides the type of integer vector.
  IntegerVectorDataType(const yy::location& location,
                        const IntegerVectorType& integer_vector_type);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The type of integer vector.
  IntegerVectorType integer_vector_type_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INTEGER_VECTOR_DATA_TYPE_H_
