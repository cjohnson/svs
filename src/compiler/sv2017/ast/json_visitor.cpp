// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/json_visitor.h"

#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/integer_vector_type.h"
#include "compiler/sv2017/ast/lifetime.h"
#include "compiler/sv2017/ast/port_direction.h"

using JsonVisitor = svs::sv2017::ast::JsonVisitor;

std::string JsonVisitor::result() { return result_.dump(2); }

void JsonVisitor::Visit(AnsiPortDeclaration& ansi_port_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "ansi_port_declaration",
                 ansi_port_declaration.location());

  ansi_port_declaration.header()->Accept(*this);
  json["header"] = result_;

  json["identifier"] = ansi_port_declaration.identifier();

  result_ = json;
}

void JsonVisitor::Visit(IntegerVectorDataType& integer_vector_data_type) {
  nlohmann::json json;
  AssignMetaTags(json, "integer_vector_data_type",
                 integer_vector_data_type.location());

  json["integer_vector_type"] = SerializeIntegerVectorType(
      integer_vector_data_type.integer_vector_type());

  result_ = json;
}

void JsonVisitor::Visit(ModuleAnsiHeader& module_ansi_header) {
  nlohmann::json json;
  AssignMetaTags(json, "module_ansi_header", module_ansi_header.location());

  json["identifier"] = module_ansi_header.identifier();

  if (module_ansi_header.lifetime().has_value())
    json["lifetime"] = SerializeLifetime(module_ansi_header.lifetime().value());

  std::vector<nlohmann::json> ports_json;
  ports_json.reserve(module_ansi_header.ports().size());
  for (const std::unique_ptr<AnsiPortDeclaration>& port :
       module_ansi_header.ports()) {
    port->Accept(*this);
    ports_json.emplace_back(result_);
  }
  json["ports"] = ports_json;

  result_ = json;
}

void JsonVisitor::Visit(ModuleDeclaration& module_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "module_declaration", module_declaration.location());

  module_declaration.header()->Accept(*this);
  json["header"] = result_;

  if (module_declaration.timeunits_declaration()) {
    module_declaration.timeunits_declaration()->Accept(*this);
    json["timeunits_declaration"] = result_;
  }

  result_ = json;
}

void JsonVisitor::Visit(SourceText& source_text) {
  nlohmann::json json;
  AssignMetaTags(json, "source_text", source_text.location());

  json["_version"] = 2017;

  std::vector<nlohmann::json> descriptions_json;
  descriptions_json.reserve(source_text.descriptions().size());

  for (const std::unique_ptr<Description>& description :
       source_text.descriptions()) {
    description->Accept(*this);
    descriptions_json.emplace_back(result_);
  }
  json["descriptions"] = descriptions_json;

  if (source_text.timeunits_declaration()) {
    source_text.timeunits_declaration()->Accept(*this);
    json["timeunits_declaration"] = result_;
  }

  result_ = json;
}

void JsonVisitor::Visit(TimeLiteral& time_literal) {
  nlohmann::json json;
  AssignMetaTags(json, "time_literal", time_literal.location());

  json["time_unit"] = SerializeTimeUnitAbbreviated(time_literal.time_unit());
  json["value"] = time_literal.value();

  result_ = json;
}

void JsonVisitor::Visit(TimeunitsDeclaration& timeunits_declaration) {
  nlohmann::json json;
  AssignMetaTags(json, "timeunits_declaration",
                 timeunits_declaration.location());

  if (timeunits_declaration.time_precision()) {
    timeunits_declaration.time_precision()->Accept(*this);
    json["time_precision"] = result_;
  }

  if (timeunits_declaration.time_unit()) {
    timeunits_declaration.time_unit()->Accept(*this);
    json["time_unit"] = result_;
  }

  result_ = json;
}

void JsonVisitor::Visit(VariablePortHeader& variable_port_header) {
  nlohmann::json json;
  AssignMetaTags(json, "variable_port_header", variable_port_header.location());

  if (variable_port_header.port_direction().has_value()) {
    std::string port_direction_string =
        SerializePortDirection(variable_port_header.port_direction().value());
    json["port_direction"] = port_direction_string;
  }

  variable_port_header.variable_port_type()->Accept(*this);
  json["variable_port_type"] = result_;

  result_ = json;
}

void JsonVisitor::AssignMetaTags(nlohmann::json& json,
                                 const std::string& node_type_name,
                                 const yy::location& location) {
  json["_type"] = node_type_name;

  std::ostringstream serialized_location;
  serialized_location << location;
  json["_location"] = serialized_location.str();
}
