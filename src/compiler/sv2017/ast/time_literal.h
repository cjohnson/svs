// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_TIME_LITERAL_H_
#define SRC_COMPILER_SV2017_AST_TIME_LITERAL_H_

#include <string>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/ast/time_unit.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A time literal
class TimeLiteral : public Node {
 public:
  // Constructs a time literal with the provided location, value, and time unit
  TimeLiteral(const yy::location& location, const std::string& value,
              const TimeUnit& time_unit);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The value of the time literal
  std::string value_;

  // The time unit of the time literal
  TimeUnit time_unit_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_TIME_LITERAL_H_
