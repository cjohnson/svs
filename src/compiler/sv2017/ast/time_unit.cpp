// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/time_unit.h"

#include <cassert>
#include <string>

using TimeUnit = svs::sv2017::ast::TimeUnit;
namespace ast = svs::sv2017::ast;

std::string ast::SerializeTimeUnit(const TimeUnit& time_unit) {
  switch (time_unit) {
    case TimeUnit::kSeconds:
      return "seconds";
    case TimeUnit::kMilliseconds:
      return "milliseconds";
    case TimeUnit::kMicroseconds:
      return "microseconds";
    case TimeUnit::kNanoseconds:
      return "nanoseconds";
    case TimeUnit::kPicoseconds:
      return "picoseconds";
    case TimeUnit::kFemtoseconds:
      return "femtoseconds";
  }
  assert(false && "Invalid time unit provided.");
  return "";
}

std::string ast::SerializeTimeUnitAbbreviated(const TimeUnit& time_unit) {
  switch (time_unit) {
    case TimeUnit::kSeconds:
      return "s";
    case TimeUnit::kMilliseconds:
      return "ms";
    case TimeUnit::kMicroseconds:
      return "us";
    case TimeUnit::kNanoseconds:
      return "ns";
    case TimeUnit::kPicoseconds:
      return "ps";
    case TimeUnit::kFemtoseconds:
      return "fs";
  }
  assert(false && "Invalid time unit provided.");
  return "";
}
