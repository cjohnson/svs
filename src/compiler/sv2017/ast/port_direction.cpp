#include "compiler/sv2017/ast/port_direction.h"

#include <cassert>
#include <string>

using PortDirection = svs::sv2017::ast::PortDirection;
namespace ast = svs::sv2017::ast;

std::string ast::SerializePortDirection(const PortDirection &port_direction) {
  switch (port_direction) {
    case PortDirection::kInput:
      return "input";
    case PortDirection::kOutput:
      return "output";
    case PortDirection::kInout:
      return "inout";
    case PortDirection::kRef:
      return "ref";
  }
  assert(false && "Invalid port direction provided.");
  return "";
}
