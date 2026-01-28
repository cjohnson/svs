// Copyright (c) 2026 Collin Johnson

#include "simulator/simulator.h"

#include <cassert>
#include <memory>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/initial_construct.h"
#include "compiler/sv2017/ast/seq_block.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/ast/subroutine_call_statement.h"
#include "compiler/sv2017/ast/system_tf_call.h"
#include "simulator/display_statement.h"
#include "simulator/sequential_block.h"
#include "simulator/statement.h"

using Simulator = svs::sim::Simulator;
using Statement = svs::sim::Statement;

std::queue<std::unique_ptr<Statement>>
Simulator::SimulatorContextFactory::Schedule(
    std::unique_ptr<svs::sv2017::ast::SourceText>& source_text) {
  source_text->Accept(*this);
  return std::move(schedule_);
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::SourceText& source_text) {
  for (const std::unique_ptr<sv2017::ast::Description>& description :
       source_text.descriptions()) {
    description->Accept(*this);
  }
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::ModuleDeclaration& module_declaration) {
  for (const std::unique_ptr<sv2017::ast::ModuleItem>& item :
       module_declaration.items()) {
    item->Accept(*this);
  }
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::InitialConstruct& initial_construct) {
  initial_construct.statement()->Accept(*this);
  schedule_.push(std::move(statement_buffer_));
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::SeqBlock& seq_block) {
  std::vector<std::unique_ptr<Statement>> statements;
  statements.reserve(seq_block.statements().size());
  for (const std::unique_ptr<sv2017::ast::Statement>& statement :
       seq_block.statements()) {
    statement->Accept(*this);
    statements.push_back(std::move(statement_buffer_));
  }

  statement_buffer_ = std::make_unique<SequentialBlock>(std::move(statements));
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::SubroutineCallStatement& subroutine_call_statement) {
  subroutine_call_statement.subroutine_call()->Accept(*this);
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::SystemTfCall& system_tf_call) {
  // TODO replace with a semantic check and call in the symbol table later
  if (system_tf_call.system_tf_identifier() == "$display") {
    assert(system_tf_call.arguments().size() == 1);

    system_tf_call.arguments()[0]->Accept(*this);
    statement_buffer_ =
        std::make_unique<DisplayStatement>(std::move(string_buffer_));
    return;
  }

  assert(false && "Expected a display statement");
}

void Simulator::SimulatorContextFactory::Visit(
    sv2017::ast::StringLiteral& string_literal) {
  string_buffer_ = string_literal.value();
}

Simulator::Simulator(std::unique_ptr<svs::sv2017::ast::SourceText> source_text,
                     std::string top_level_module_identifier)
    : source_text_(std::move(source_text)),
      top_level_module_identifier_(top_level_module_identifier) {
  std::vector<std::unique_ptr<Statement>> sequential_block_schedule;
  sequential_block_schedule.reserve(1);
  sequential_block_schedule.push_back(
      std::make_unique<DisplayStatement>("test"));

  auto sequential_block =
      std::make_unique<SequentialBlock>(std::move(sequential_block_schedule));
  schedule_.push(std::move(sequential_block));
}

void Simulator::Run() {
  // Build the simulator context
  SimulatorContextFactory simulator_context_factory;
  schedule_ = simulator_context_factory.Schedule(source_text_);

  while (!schedule_.empty()) {
    std::unique_ptr<Statement> statement = std::move(schedule_.front());
    schedule_.pop();

    statement->Execute();
  }
}
