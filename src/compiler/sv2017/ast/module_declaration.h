// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <memory>
#include <string>

#include "ast.h"
#include "node.h"

namespace svs::sv2017::ast {

// A module header. Defines the public interface for the module.
class ModuleHeader : public Node {
 public:
  // Constructs a module header.
  // Client passes the module identifier.
  explicit ModuleHeader(const std::string& identifier);

 protected:
  // The identifier for the module.
  std::string identifier_;
};

// An ANSI-style module header.
class ModuleAnsiHeader : public ModuleHeader {
 public:
  // Constructs an ANSI-style module header.
  // Client passes the module identifier.
  explicit ModuleAnsiHeader(const std::string& identifier);

  // Returns a json representation of the tree.
  std::string to_json(size_t indent_level = 0) override;
};

// A SystemVerilog module declaration.
class ModuleDeclaration : public Node {
 public:
    // Constructs a module declaration.
    // Client passes the module header.
    explicit ModuleDeclaration(std::unique_ptr<ModuleHeader> header);

    // Returns a json representation of the tree.
    std::string to_json(size_t indent_level = 0) override;

 private:
    // The module header
    std::unique_ptr<ModuleHeader> header_;

    friend yy::parser;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
