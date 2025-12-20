// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_
#define SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A number specified in hex
class HexNumber : public Node {
 public:
  // Constructs a hex number with the provided location and signedness.
  HexNumber(const yy::location& location, const Signedness signedness);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

 private:
  // The signedness of the number.
  Signedness signedness_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_HEX_NUMBER_H_
