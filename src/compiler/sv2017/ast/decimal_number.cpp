// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/decimal_number.h"

#include <string>

#include "compiler/sv2017/ast/visitor.h"

using DecimalNumber = svs::sv2017::ast::DecimalNumber;

DecimalNumber::DecimalNumber(const yy::location& location,
                             const std::optional<std::string>& size,
                             const Signedness signedness,
                             const std::string& value)
    : IntegralNumber(location, size, signedness, value) {}

void DecimalNumber::Accept(Visitor& visitor) { visitor.Visit(*this); }
