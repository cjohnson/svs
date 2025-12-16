// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/lifetime.h"

#include <cassert>
#include <string>

using Lifetime = svs::sv2017::ast::Lifetime;
namespace ast = svs::sv2017::ast;

std::string ast::SerializeLifetime(const Lifetime &lifetime) {
  switch (lifetime) {
    case Lifetime::kStatic:
      return "static";
    case Lifetime::kAutomatic:
      return "automatic";
  }
  assert(false && "Invalid lifetime provided");
  return "";
}
