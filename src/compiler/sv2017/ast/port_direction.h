// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_PORT_DIRECTION_H_
#define SRC_COMPILER_SV2017_AST_PORT_DIRECTION_H_

namespace svs::sv2017::ast {

// The port direction
enum class PortDirection {
  kInput,
  kOutput,
  kInout,
  kRef,
};

}

#endif  // SRC_COMPILER_SV2017_AST_PORT_DIRECTION_H_
