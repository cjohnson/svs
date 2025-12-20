// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/hex_number.h"

#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using HexNumber = svs::sv2017::ast::HexNumber;

HexNumber::HexNumber(const yy::location& location, const Signedness signedness)
    : Node(location), signedness_(signedness) {}

void HexNumber::Accept(Visitor& visitor) { visitor.Visit(*this); }
