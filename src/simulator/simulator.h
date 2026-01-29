// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_SIMULATOR_H_
#define SRC_SIMULATOR_SIMULATOR_H_

#include <memory>
#include <queue>

#include "compiler/sv2017/ast/initial_construct.h"
#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/partial_visitor.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/ast/subroutine_call_statement.h"
#include "compiler/sv2017/ast/system_tf_call.h"
#include "simulator/statement.h"

namespace svs::sim {

// A simulator
class Simulator {
 public:
  // Visitor class that constructs the simulator context.
  class SimulatorContextFactory : public sv2017::ast::PartialVisitor {
   public:
    std::queue<std::unique_ptr<Statement>> Schedule(
        std::unique_ptr<svs::sv2017::ast::SourceText>& source_text);

   private:
    void Visit(sv2017::ast::SourceText& source_text) override;
    void Visit(sv2017::ast::ModuleDeclaration& module_declaration) override;
    void Visit(sv2017::ast::InitialConstruct& initial_construct) override;
    void Visit(sv2017::ast::SeqBlock& seq_block) override;
    void Visit(sv2017::ast::SubroutineCallStatement& subroutine_call_statement)
        override;
    void Visit(sv2017::ast::SystemTfCall& system_tf_call) override;
    void Visit(sv2017::ast::StringLiteral& string_literal) override;

    std::queue<std::unique_ptr<Statement>> schedule_;

    std::unique_ptr<Statement> statement_buffer_;
    std::string string_buffer_;
  };

  // Constructs a simulator with the provided sv2017 ast and top-level module
  // identifier.
  Simulator();

  // Run the simulation.
  void Run(std::unique_ptr<svs::sv2017::ast::SourceText>& source_text);

 private:
  std::queue<std::unique_ptr<Statement>> schedule_;
};

};  // namespace svs::sim

#endif  // SRC_SIMULATOR_SIMULATOR_H_
