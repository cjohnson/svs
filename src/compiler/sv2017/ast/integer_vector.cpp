#include "integer_vector_data_type.h"

using IntegerVectorDataType = svs::sv2017::ast::IntegerVectorDataType;

IntegerVectorDataType::IntegerVectorDataType(const IntegerVectorType& type)
  : type_(type) { }

