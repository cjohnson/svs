// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_VHWD_MODULE_H_
#define SRC_COMPILER_VHWD_MODULE_H_

#include <string>
#include <unordered_map>

namespace svs::vhwd {

struct Module {
  std::string identifier;
  std::unordered_map<std::string, std::string> signals;
};

}  // namespace svs::vhwd

#endif  // SRC_COMPILER_VHWD_MODULE_H_
