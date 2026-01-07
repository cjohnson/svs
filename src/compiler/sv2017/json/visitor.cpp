// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/json/visitor.h"

#include <memory>
#include <string>
#include <vector>

#include "compiler/sv2017/ast/ansi_port_declaration.h"
#include "compiler/sv2017/ast/continuous_assign.h"
#include "compiler/sv2017/ast/decimal_number.h"
#include "compiler/sv2017/ast/initial_construct.h"
#include "compiler/sv2017/ast/integer_vector_type.h"
#include "compiler/sv2017/ast/lifetime.h"
#include "compiler/sv2017/ast/net_assignment.h"
#include "compiler/sv2017/ast/port_direction.h"
#include "compiler/sv2017/ast/signedness.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"

using Visitor = svs::sv2017::json::Visitor;

nlohmann::json Visitor::Serialize(ast::Node& node) {
  result_ = {};
  node.Accept(*this);

  return result_;
}

nlohmann::json Visitor::Serialize(const ast::Signedness& signedness) {
  switch (signedness) {
    case ast::Signedness::kSigned:
      return "signed";
    case ast::Signedness::kUnsigned:
      return "unsigned";
  }

  assert(false && "Provided with an invalid signedness.");
  return {};
}

void Visitor::Visit(ast::AnsiPortDeclaration& ansi_port_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "ansi_port_declaration",
                 ansi_port_declaration.location());

  json["header"] = Serialize(*ansi_port_declaration.header());
  json["identifier"] = ansi_port_declaration.identifier();

  result_ = json;
}

void Visitor::Visit(ast::Attribute& attribute) {
  nlohmann::json json;
  AssignMetaTags(json, "attr_spec", attribute.location());

  json["name"] = attribute.name();
  if (attribute.value()) json["value"] = Serialize(*attribute.value());

  result_ = json;
}

void Visitor::Visit(ast::ContinuousAssign& continuous_assign) {
  nlohmann::json json;
  AssignMetaTags(json, "continuous_assign", continuous_assign.location());

  std::vector<nlohmann::json> net_assignments_json;
  net_assignments_json.reserve(continuous_assign.net_assignments().size());
  for (const std::unique_ptr<ast::NetAssignment>& net_assignment :
       continuous_assign.net_assignments())
    net_assignments_json.push_back(Serialize(*net_assignment));

  json["net_assignments"] = net_assignments_json;

  result_ = json;
}

void Visitor::Visit(ast::DecimalNumber& decimal_number) {
  nlohmann::json json;
  AssignMetaTags(json, "decimal_number", decimal_number.location());

  if (decimal_number.size().has_value())
    json["size"] = decimal_number.size().value();

  json["signedness"] = Serialize(decimal_number.signedness());
  json["value"] = decimal_number.value();

  result_ = json;
}

void Visitor::Visit(ast::HexNumber& hex_number) {
  nlohmann::json json;
  AssignMetaTags(json, "hex_number", hex_number.location());

  if (hex_number.size().has_value()) json["size"] = hex_number.size().value();

  json["signedness"] = Serialize(hex_number.signedness());
  json["value"] = hex_number.value();

  result_ = json;
}

void Visitor::Visit(ast::InitialConstruct& initial_construct) {
  nlohmann::json json;
  AssignMetaTags(json, "initial_construct", initial_construct.location());

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

  const std::vector<std::unique_ptr<ast::Attribute>>& attributes =
      module_ansi_header.attributes();
  std::vector<nlohmann::json> attributes_json;
  attributes_json.reserve(attributes.size());
  for (const std::unique_ptr<ast::Attribute>& attribute : attributes)
    attributes_json.push_back(Serialize(*attribute));
  json["attributes"] = attributes_json;

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

  std::vector<nlohmann::json> items_json;
  items_json.reserve(module_declaration.items().size());
  for (const std::unique_ptr<ast::ModuleItem>& module_item :
       module_declaration.items())
    items_json.push_back(Serialize(*module_item));
  json["items"] = items_json;

  result_ = json;
}

void Visitor::Visit(ast::NetAssignment& net_assignment) {
  nlohmann::json json;
  AssignMetaTags(json, "net_assignment", net_assignment.location());

  json["net_lvalue"] = net_assignment.net_lvalue();
  json["expression"] = Serialize(*net_assignment.expression());

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
