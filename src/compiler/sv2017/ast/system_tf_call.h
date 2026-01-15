// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SYSTEM_TF_CALL_H_
#define SRC_COMPILER_SV2017_AST_SYSTEM_TF_CALL_H_

#include <string>
#include <vector>

#include "compiler/sv2017/ast/subroutine_call.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A system task or function call.
class SystemTfCall : public SubroutineCall {
 public:
  // Constructs a system task or function call
  SystemTfCall(const yy::location& location, std::string system_tf_identifier,
               std::vector<std::unique_ptr<Expression>> arguments);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The system task or function identifier.
  inline const std::string& system_tf_identifier() {
    return system_tf_identifier_;
  }

 private:
  std::string system_tf_identifier_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SYSTEM_TF_CALL_H_
