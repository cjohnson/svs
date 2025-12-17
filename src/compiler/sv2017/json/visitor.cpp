// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/json/visitor.h"

#include <memory>
#include <string>
#include <vector>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/integer_vector_type.h"
#include "compiler/sv2017/ast/lifetime.h"
#include "compiler/sv2017/ast/port_direction.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"

using Visitor = svs::sv2017::json::Visitor;

nlohmann::json Visitor::Serialize(ast::Node& node) {
  result_ = {};
  node.Accept(*this);

  return result_;
}

void Visitor::Visit(ast::AnsiPortDeclaration& ansi_port_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "ansi_port_declaration",
                 ansi_port_declaration.location());

  json["header"] = Serialize(*ansi_port_declaration.header());
  json["identifier"] = ansi_port_declaration.identifier();

  result_ = json;
}

void Visitor::Visit(ast::IntegerVectorDataType& integer_vector_data_type) {
  nlohmann::json json;
  AssignMetaTags(json, "integer_vector_data_type",
                 integer_vector_data_type.location());

  json["integer_vector_type"] = SerializeIntegerVectorType(
      integer_vector_data_type.integer_vector_type());

  result_ = json;
}

void Visitor::Visit(ast::ModuleAnsiHeader& module_ansi_header) {
  nlohmann::json json;
  AssignMetaTags(json, "module_ansi_header", module_ansi_header.location());

  json["identifier"] = module_ansi_header.identifier();

  const std::optional<ast::Lifetime>& lifetime = module_ansi_header.lifetime();
  if (lifetime.has_value())
    json["lifetime"] = SerializeLifetime(lifetime.value());

  const std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>& ports =
      module_ansi_header.ports();
  std::vector<nlohmann::json> ports_json;
  ports_json.reserve(ports.size());
  for (const std::unique_ptr<ast::AnsiPortDeclaration>& port : ports)
    ports_json.emplace_back(Serialize(*port));
  json["ports"] = ports_json;

  result_ = json;
}

void Visitor::Visit(ast::ModuleDeclaration& module_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "module_declaration", module_declaration.location());

  json["header"] = Serialize(*module_declaration.header());

  const std::unique_ptr<ast::TimeunitsDeclaration>& timeunits_declaration =
      module_declaration.timeunits_declaration();
  if (timeunits_declaration)
    json["timeunits_declaration"] = Serialize(*timeunits_declaration);

  result_ = json;
}

void Visitor::Visit(ast::SourceText& source_text) {
  nlohmann::json json;
  AssignMetaTags(json, "source_text", source_text.location());

  json["_version"] = 2017;

  const std::vector<std::unique_ptr<ast::Description>>& descriptions =
      source_text.descriptions();
  std::vector<nlohmann::json> descriptions_json;
  descriptions_json.reserve(descriptions.size());
  for (const std::unique_ptr<ast::Description>& description : descriptions)
    descriptions_json.emplace_back(Serialize(*description));
  json["descriptions"] = descriptions_json;

  const std::unique_ptr<ast::TimeunitsDeclaration>& timeunits_declaration =
      source_text.timeunits_declaration();
  if (timeunits_declaration)
    json["timeunits_declaration"] = Serialize(*timeunits_declaration);

  result_ = json;
}

void Visitor::Visit(ast::TimeLiteral& time_literal) {
  nlohmann::json json;
  AssignMetaTags(json, "time_literal", time_literal.location());

  json["time_unit"] = SerializeTimeUnitAbbreviated(time_literal.time_unit());
  json["value"] = time_literal.value();

  result_ = json;
}

void Visitor::Visit(ast::TimeunitsDeclaration& timeunits_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "timeunits_declaration",
                 timeunits_declaration.location());

  const std::unique_ptr<ast::TimeLiteral>& time_precision =
      timeunits_declaration.time_precision();
  if (time_precision) json["time_precision"] = Serialize(*time_precision);

  const std::unique_ptr<ast::TimeLiteral>& time_unit =
      timeunits_declaration.time_unit();
  if (time_unit) json["time_unit"] = Serialize(*time_unit);

  result_ = json;
}

void Visitor::Visit(ast::VariablePortHeader& variable_port_header) {
  nlohmann::json json;
  AssignMetaTags(json, "variable_port_header", variable_port_header.location());

  const std::optional<ast::PortDirection> port_direction =
      variable_port_header.port_direction();
  if (port_direction.has_value())
    json["port_direction"] = SerializePortDirection(port_direction.value());

  json["variable_port_type"] =
      Serialize(*variable_port_header.variable_port_type());

  result_ = json;
}

void Visitor::AssignMetaTags(nlohmann::json& json,
                             const std::string& node_type_name,
                             const yy::location& location) {
  json["_type"] = node_type_name;

  std::ostringstream serialized_location;
  serialized_location << location;
  json["_location"] = serialized_location.str();
}
