// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/node.h"

#include "compiler/sv2017/location.hh"

using Node = svs::sv2017::ast::Node;

Node::Node(const yy::location& location) : location_(location) {}

const yy::location& Node::location() { return location_; }
