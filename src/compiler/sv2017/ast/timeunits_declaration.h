// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_TIMEUNITS_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_TIMEUNITS_DECLARATION_H_

#include <memory>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/time_literal.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A timeunits declaration
class TimeunitsDeclaration : public Node {
 public:
  // Constructs a timeunits declaration with the provided time unit and time
  // precision
  TimeunitsDeclaration(const yy::location& location,
                       std::unique_ptr<TimeLiteral> time_unit,
                       std::unique_ptr<TimeLiteral> time_precision);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The time unit - the unit of measurement for times and delays.
  std::unique_ptr<TimeLiteral> time_unit_;

  // The time precision - specifies the degree of accuracy for delays.
  std::unique_ptr<TimeLiteral> time_precision_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_TIMEUNITS_DECLARATION_H_
