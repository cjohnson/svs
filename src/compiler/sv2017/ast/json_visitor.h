// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_JSON_VISITOR_H_
#define SRC_COMPILER_SV2017_AST_JSON_VISITOR_H_

#include <nlohmann/json.hpp>
#include <string>

#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

class JsonVisitor : public Visitor {
 public:
  // The json result from visiting the AST.
  std::string result();

  void Visit(AnsiPortDeclaration& ansi_port_declaration) override;
  void Visit(IntegerVectorDataType& integer_vector_data_type) override;
  void Visit(ModuleAnsiHeader& module_ansi_header) override;
  void Visit(ModuleDeclaration& module_declaration) override;
  void Visit(SourceText& source_text) override;
  void Visit(TimeLiteral& time_literal) override;
  void Visit(TimeunitsDeclaration& timeunits_declaration) override;
  void Visit(VariablePortHeader& variable_port_header) override;

 private:
  // Assign node meta tags to the provided json object.
  void AssignMetaTags(nlohmann::json& json, const std::string& node_type_name,
                      const yy::location& location);

  nlohmann::json result_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_JSON_VISITOR_H_
