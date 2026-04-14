// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_VHWD_SOURCE_H_
#define SRC_COMPILER_VHWD_SOURCE_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "compiler/vhwd/module.h"

namespace svs::vhwd {

struct Source {
  std::unordered_map<std::string, std::unique_ptr<Module>> modules;
};

}  // namespace svs::vhwd

#endif  // SRC_COMPILER_VHWD_SOURCE_H_
