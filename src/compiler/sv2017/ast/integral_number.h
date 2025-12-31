// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INTEGRAL_NUMBER_H_
#define SRC_COMPILER_SV2017_AST_INTEGRAL_NUMBER_H_

#include <optional>
#include <string>

#include "compiler/sv2017/ast/expression.h"
#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An integral number.
class IntegralNumber : public Expression {
 public:
  // Constructs a hex number with the provided location, optional size,
  // signedness, and value.
  IntegralNumber(const yy::location& location,
                 const std::optional<std::string>& size,
                 const Signedness signedness, const std::string& value);

  // The size of the number in bits.
  inline const std::optional<std::string> size() { return size_; }

  // The signedness of the number.
  inline Signedness signedness() { return signedness_; }

  // The value of the number.
  inline const std::string& value() { return value_; }

 protected:
  std::optional<std::string> size_;
  Signedness signedness_;
  std::string value_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INTEGRAL_NUMBER_H_
