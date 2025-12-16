// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_LIFETIME_H_
#define SRC_COMPILER_SV2017_AST_LIFETIME_H_

#include <string>

namespace svs::sv2017::ast {

// The lifetime
enum class Lifetime {
  // Static lifetime
  kStatic,

  // Automatic lifetime
  kAutomatic,
};

// Serializes the provided lifetime as a string.
std::string SerializeLifetime(const Lifetime& lifetime);

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_LIFETIME_H_
