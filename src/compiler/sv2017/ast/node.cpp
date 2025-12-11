// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/node.h"

#include <sstream>

#include <nlohmann/json.hpp>
#include "compiler/sv2017/location.hh"

using json = nlohmann::json;
using Node = svs::sv2017::ast::Node;

Node::Node(const yy::location& location) : location_(location) {}

json Node::MarshallJson() {
  json j;

  std::ostringstream serialized_location;
  serialized_location << location_;

  j["_location"] = serialized_location.str();

  return j;
}

const yy::location& Node::location() {
  return location_;
}
