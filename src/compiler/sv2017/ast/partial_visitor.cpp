// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/ast/partial_visitor.h"

#include <cassert>

using PartialVisitor = svs::sv2017::ast::PartialVisitor;

void PartialVisitor::Visit(AnsiPortDeclaration& ansi_port_declaration) {
  assert(false);
}

void PartialVisitor::Visit(Attribute& attribute) { assert(false); }

void PartialVisitor::Visit(BlockingAssignment& blocking_assignment) {
  assert(false);
}

void PartialVisitor::Visit(ContinuousAssign& continuous_assign) {
  assert(false);
}

void PartialVisitor::Visit(DataDeclaration& data_declaration) { assert(false); }

void PartialVisitor::Visit(DecimalNumber& decimal_number) { assert(false); }

void PartialVisitor::Visit(HexNumber& hex_number) { assert(false); }

void PartialVisitor::Visit(InitialConstruct& initial_construct) {
  assert(false);
}

void PartialVisitor::Visit(IntegerVectorDataType& integer_vector_data_type) {
  assert(false);
}

void PartialVisitor::Visit(ModuleAnsiHeader& module_ansi_header) {
  assert(false);
}

void PartialVisitor::Visit(ModuleDeclaration& module_declaration) {
  assert(false);
}

void PartialVisitor::Visit(NetAssignment& net_assignment) { assert(false); }

void PartialVisitor::Visit(SeqBlock& seq_block) { assert(false); }

void PartialVisitor::Visit(SourceText& source_text) { assert(false); }

void PartialVisitor::Visit(StringLiteral& string_literal) { assert(false); }

void PartialVisitor::Visit(SubroutineCallStatement& subroutine_call_statement) {
  assert(false);
}

void PartialVisitor::Visit(SystemTfCall& system_tf_call) { assert(false); }

void PartialVisitor::Visit(TimeLiteral& time_literal) { assert(false); }

void PartialVisitor::Visit(TimeunitsDeclaration& timeunits_declaration) {
  assert(false);
}

void PartialVisitor::Visit(VariableDeclAssignment& variable_decl_assignment) {
  assert(false);
}

void PartialVisitor::Visit(VariablePortHeader& variable_port_header) {
  assert(false);
}
