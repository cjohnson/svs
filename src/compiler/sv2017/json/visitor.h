// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_JSON_VISITOR_H_
#define SRC_COMPILER_SV2017_JSON_VISITOR_H_

#include <string>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/continuous_assign.h"
#include "compiler/sv2017/ast/hex_number.h"
#include "compiler/sv2017/ast/net_assignment.h"
#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::json {

class Visitor : public ast::Visitor {
 public:
  // Serializes the provided node into json.
  nlohmann::json Serialize(ast::Node& node);

  void Visit(ast::AnsiPortDeclaration& ansi_port_declaration) override;
  void Visit(ast::Attribute& attribute) override;
  void Visit(ast::ContinuousAssign& continuous_assign) override;
  void Visit(ast::HexNumber& hex_number) override;
  void Visit(ast::IntegerVectorDataType& integer_vector_data_type) override;
  void Visit(ast::ModuleAnsiHeader& module_ansi_header) override;
  void Visit(ast::ModuleDeclaration& module_declaration) override;
  void Visit(ast::NetAssignment& net_assignment) override;
  void Visit(ast::SourceText& source_text) override;
  void Visit(ast::TimeLiteral& time_literal) override;
  void Visit(ast::TimeunitsDeclaration& timeunits_declaration) override;
  void Visit(ast::VariablePortHeader& variable_port_header) override;

 private:
  // Assign node meta tags to the provided json object.
  void AssignMetaTags(nlohmann::json& json, const std::string& node_type_name,
                      const yy::location& location);

  nlohmann::json result_;
};

}  // namespace svs::sv2017::json

#endif  // SRC_COMPILER_SV2017_JSON_VISITOR_H_
