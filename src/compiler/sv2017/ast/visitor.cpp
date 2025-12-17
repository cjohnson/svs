// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/visitor.h"

using Visitor = svs::sv2017::ast::Visitor;

void Visitor::Visit(AnsiPortDeclaration& ansi_port_declaration) {}
void Visitor::Visit(IntegerVectorDataType& integer_vector_data_type) {}
void Visitor::Visit(ModuleAnsiHeader& module_ansi_header) {}
void Visitor::Visit(ModuleDeclaration& module_declaration) {}
void Visitor::Visit(ModuleHeader& module_header) {}
void Visitor::Visit(SourceText& source_text) {}
void Visitor::Visit(TimeLiteral& time_literal) {}
void Visitor::Visit(TimeunitsDeclaration& timeunits_declaration) {}
void Visitor::Visit(VariablePortHeader& variable_port_header) {}
