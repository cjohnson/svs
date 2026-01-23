// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_STRING_LITERAL_H_
#define SRC_COMPILER_SV2017_AST_STRING_LITERAL_H_

#include "compiler/sv2017/ast/expression.h"

namespace svs::sv2017::ast {

// A string literal.
class StringLiteral : public Expression {
 public:
  // Constructs a string literal with the provided location and value
  StringLiteral(const yy::location& location, std::string value);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The value of the string literal.
  inline const std::string& value() { return value_; }

 private:
  std::string value_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_STRING_LITERAL_H_
