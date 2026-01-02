// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_VISITOR_H_
#define SRC_COMPILER_SV2017_AST_VISITOR_H_

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/attribute.h"
#include "compiler/sv2017/ast/hex_number.h"
#include "compiler/sv2017/ast/integer_vector_data_type.h"
#include "compiler/sv2017/ast/module_ansi_header.h"
#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/net_assignment.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/ast/time_literal.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/ast/variable_port_header.h"

namespace svs::sv2017::ast {

// Visitor for the AST.
class Visitor {
 public:
  virtual void Visit(AnsiPortDeclaration& ansi_port_declaration) = 0;
  virtual void Visit(Attribute& attribute) = 0;
  virtual void Visit(HexNumber& hex_number) = 0;
  virtual void Visit(IntegerVectorDataType& integer_vector_data_type) = 0;
  virtual void Visit(ModuleAnsiHeader& module_ansi_header) = 0;
  virtual void Visit(ModuleDeclaration& module_declaration) = 0;
  virtual void Visit(NetAssignment& net_assignment) = 0;
  virtual void Visit(SourceText& source_text) = 0;
  virtual void Visit(TimeLiteral& time_literal) = 0;
  virtual void Visit(TimeunitsDeclaration& timeunits_declaration) = 0;
  virtual void Visit(VariablePortHeader& variable_port_header) = 0;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_VISITOR_H_
