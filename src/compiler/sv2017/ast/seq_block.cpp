// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/seq_block.h"

#include <memory>
#include <utility>
#include <vector>

#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using SeqBlock = svs::sv2017::ast::SeqBlock;

SeqBlock::SeqBlock(const yy::location& location,
                   std::vector<std::unique_ptr<Statement>> statements)
    : Statement(location), statements_(std::move(statements)) {}

void SeqBlock::Accept(Visitor& visitor) { visitor.Visit(*this); }
