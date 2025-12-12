// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_TIME_UNIT_H_
#define SRC_COMPILER_SV2017_AST_TIME_UNIT_H_

#include <string>

namespace svs::sv2017::ast {

// An enumeration of the legal time units in SystemVerilog
enum class TimeUnit {
  // The seconds timeunit, abbrevited "s"
  kSeconds,

  // The milliseconds timeunit, abbreviated "ms"
  kMilliseconds,

  // The microseconds timeunit, abbreviated "us"
  kMicroseconds,

  // The nanoseconds timeunit, abbreviated "ns"
  kNanoseconds,

  // The picoseconds timeunit, abbreviated "ps"
  kPicoseconds,

  // The femtoseconds timeunit, abbreviated "fs"
  kFemtoseconds,
};

// Serialize the provided time unit as a full name.
std::string SerializeTimeUnit(const TimeUnit& time_unit);

// Serialize the provided time unit as its abbreviated dimensional analysis
// identifier.
std::string SerializeTimeUnitAbbreviated(const TimeUnit& time_unit);

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_TIME_UNIT_H_
