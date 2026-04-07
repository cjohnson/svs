// Copyright (c) 2026 Collin Johnson

#include "simulator/simulator.h"

#include <cassert>
#include <memory>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/initial_construct.h"
#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/seq_block.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/ast/subroutine_call_statement.h"
#include "compiler/sv2017/ast/system_tf_call.h"
#include "simulator/display_statement.h"
#include "simulator/sequential_block.h"
#include "simulator/statement.h"

using Module = svs::sim::Module;
using ModuleElaborator = svs::sim::ModuleElaborator;
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

std::unique_ptr<Module> ModuleElaborator::Elaborate(
    sv2017::ast::ModuleDeclaration& module_declaration) {
  module_declaration.Accept(*this);
  return std::move(module_);
}

void ModuleElaborator::Visit(
    sv2017::ast::ModuleDeclaration& module_declaration) {
  module_ = std::make_unique<Module>();
}

Simulator::Simulator() {}

void Simulator::Run(
    std::unique_ptr<svs::sv2017::ast::SourceText>& source_text) {
  Visit(*source_text);
  for (auto& [name, module] : modules_) {
    std::cout << "Found module: " << name << "\n";
  }
}

void Simulator::Visit(sv2017::ast::SourceText& source_text) {
  for (const std::unique_ptr<sv2017::ast::Description>& description :
       source_text.descriptions())
    description->Accept(*this);
}

void Simulator::Visit(sv2017::ast::ModuleDeclaration& module_declaration) {
  ModuleElaborator module_elaborator;
  modules_[module_declaration.header()->identifier()] =
      std::move(module_elaborator.Elaborate(module_declaration));
}
