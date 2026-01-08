// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SEQ_BLOCK_H_
#define SRC_COMPILER_SV2017_AST_SEQ_BLOCK_H_

#include <memory>
#include <vector>

#include "compiler/sv2017/ast/statement.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A sequential block.
class SeqBlock : public Statement {
 public:
  // Constructs a sequential block from the provided location and statements.
  SeqBlock(const yy::location& location,
           std::vector<std::unique_ptr<Statement>> statements);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The statements within the block.
  inline const std::vector<std::unique_ptr<Statement>>& statements() {
    return statements_;
  }

 private:
  std::vector<std::unique_ptr<Statement>> statements_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SEQ_BLOCK_H_
