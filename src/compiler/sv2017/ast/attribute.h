// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_ATTRIBUTE_H_
#define SRC_COMPILER_SV2017_AST_ATTRIBUTE_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/expression.h"
#include "compiler/sv2017/ast/node.h"

namespace svs::sv2017::ast {

class Attribute : public Node {
 public:
  // Constructs an attribute with the provided location, name, and value.
  Attribute(const yy::location& location, const std::string& name,
            std::unique_ptr<Expression> value);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The name of the attribute.
  inline const std::string& name() { return name_; }

  // The value of the attribute, if provided; nullptr otherwise.
  inline const std::unique_ptr<Expression>& value() { return value_; }

 private:
  std::string name_;
  std::unique_ptr<Expression> value_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_ATTRIBUTE_H_
