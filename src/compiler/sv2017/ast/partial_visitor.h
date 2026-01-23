// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_PARTIAL_VISITOR_H_
#define SRC_COMPILER_SV2017_AST_PARTIAL_VISITOR_H_

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/attribute.h"
#include "compiler/sv2017/ast/blocking_assignment.h"
#include "compiler/sv2017/ast/continuous_assign.h"
#include "compiler/sv2017/ast/data_declaration.h"
#include "compiler/sv2017/ast/decimal_number.h"
#include "compiler/sv2017/ast/hex_number.h"
#include "compiler/sv2017/ast/initial_construct.h"
#include "compiler/sv2017/ast/integer_vector_data_type.h"
#include "compiler/sv2017/ast/module_ansi_header.h"
#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/net_assignment.h"
#include "compiler/sv2017/ast/seq_block.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/ast/string_literal.h"
#include "compiler/sv2017/ast/subroutine_call_statement.h"
#include "compiler/sv2017/ast/system_tf_call.h"
#include "compiler/sv2017/ast/time_literal.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/ast/variable_decl_assignment.h"
#include "compiler/sv2017/ast/variable_port_header.h"
#include "compiler/sv2017/ast/visitor.h"

namespace svs::sv2017::ast {

class PartialVisitor : public Visitor {
 public:
  void Visit(AnsiPortDeclaration& ansi_port_declaration) override;
  void Visit(Attribute& attribute) override;
  void Visit(BlockingAssignment& blocking_assignment) override;
  void Visit(ContinuousAssign& continuous_assign) override;
  void Visit(DataDeclaration& data_declaration) override;
  void Visit(DecimalNumber& decimal_number) override;
  void Visit(HexNumber& hex_number) override;
  void Visit(InitialConstruct& initial_construct) override;
  void Visit(IntegerVectorDataType& integer_vector_data_type) override;
  void Visit(ModuleAnsiHeader& module_ansi_header) override;
  void Visit(ModuleDeclaration& module_declaration) override;
  void Visit(NetAssignment& net_assignment) override;
  void Visit(SeqBlock& seq_block) override;
  void Visit(SourceText& source_text) override;
  void Visit(StringLiteral& string_literal) override;
  void Visit(SubroutineCallStatement& subroutine_call_statement) override;
  void Visit(SystemTfCall& system_tf_call) override;
  void Visit(TimeLiteral& time_literal) override;
  void Visit(TimeunitsDeclaration& timeunits_declaration) override;
  void Visit(VariableDeclAssignment& variable_decl_assignment) override;
  void Visit(VariablePortHeader& variable_port_header) override;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_PARTIAL_VISITOR_H_
