// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/timeunits_declaration.h"

#include <memory>
#include <nlohmann/json.hpp>
#include <utility>

#include "compiler/sv2017/ast/time_literal.h"

using json = nlohmann::json;
using TimeunitsDeclaration = svs::sv2017::ast::TimeunitsDeclaration;
using TimeLiteral = svs::sv2017::ast::TimeLiteral;

TimeunitsDeclaration::TimeunitsDeclaration(
    const yy::location& location, std::unique_ptr<TimeLiteral> time_unit,
    std::unique_ptr<TimeLiteral> time_precision)
    : Node(location),
      time_unit_(std::move(time_unit)),
      time_precision_(std::move(time_precision)) {}

json TimeunitsDeclaration::MarshallJson() {
  json j = Node::MarshallJson();
  j["_type"] = "timeunits_declaration";

  if (time_unit_)
    j["time_unit"] = time_unit_->MarshallJson();
  if (time_precision_)
    j["time_precision"] = time_precision_->MarshallJson();

  return j;
}
