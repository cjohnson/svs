#include "ansi_port_declaration.h"

using AnsiPortDeclaration = svs::sv2017::ast::AnsiPortDeclaration;
using VariablePortHeader = svs::sv2017::ast::VariablePortHeader;

AnsiPortDeclaration::AnsiPortDeclaration(
    std::unique_ptr<VariablePortHeader> header,
    std::string identifier)
  : header_(std::move(header)), identifier_(std::move(identifier)) { }

std::string AnsiPortDeclaration::to_json(size_t indent_level) {
  return "";
}
