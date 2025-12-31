// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_
#define SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_

#include <string>

#include "compiler/sv2017/ast/integral_number.h"
#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A number specified in hex
class HexNumber : public IntegralNumber {
 public:
  // Constructs a hex number with the provided location, optional size,
  // signedness, and value.
  HexNumber(const yy::location& location,
            const std::optional<std::string>& size, const Signedness signedness,
            const std::string& value);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_
