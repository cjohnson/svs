// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/integral_number.h"

#include <string>

#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/location.hh"

using IntegralNumber = svs::sv2017::ast::IntegralNumber;

IntegralNumber::IntegralNumber(const yy::location& location,
                               const std::optional<std::string>& size,
                               const Signedness signedness,
                               const std::string& value)
    : Expression(location),
      size_(size),
      signedness_(signedness),
      value_(value) {}
