// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_DECIMAL_NUMBER_H_
#define SRC_COMPILER_SV2017_AST_DECIMAL_NUMBER_H_

#include <optional>
#include <string>

#include "compiler/sv2017/ast/integral_number.h"
#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A number specified in decimal
class DecimalNumber : public IntegralNumber {
 public:
  // Constructs a decimal number with the provided location, optional size,
  // signedness, and value.
  DecimalNumber(const yy::location& location,
                const std::optional<std::string>& size,
                const Signedness signedness, const std::string& value);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_DECIMAL_NUMBER_H_
