// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/time_literal.h"

#include <nlohmann/json.hpp>
#include <string>

#include "compiler/sv2017/ast/time_unit.h"
#include "compiler/sv2017/ast/visitor.h"

using json = nlohmann::json;
using TimeLiteral = svs::sv2017::ast::TimeLiteral;

TimeLiteral::TimeLiteral(const yy::location& location, const std::string& value,
                         const TimeUnit& time_unit)
    : Node(location), value_(value), time_unit_(time_unit) {}

void TimeLiteral::Accept(Visitor& visitor) { visitor.Visit(*this); }

static constexpr bool kPrintAbbreviated = true;

json TimeLiteral::MarshallJson() {
  json j = Node::MarshallJson();
  j["_type"] = "time_literal";

  j["value"] = value_;

  if constexpr (kPrintAbbreviated) {
    j["time_unit"] = SerializeTimeUnitAbbreviated(time_unit_);
  } else {
    j["time_unit"] = SerializeTimeUnit(time_unit_);
  }

  return j;
}
