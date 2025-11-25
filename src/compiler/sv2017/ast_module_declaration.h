#ifndef SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <memory>

#include "ast.h"

namespace svs::sv2017::ast {

//
// A module header.
//
class module_header_t : public node_t {
public:
    module_header_t(const std::string& identifier);

    inline const std::string& identifier() { return _identifier; }

protected:
    std::string _identifier;
};

//
// An ANSI-style module header.
//
class module_ansi_header_t : public module_header_t {
public:
    module_ansi_header_t(const std::string& identifier);

    //
    // Returns a json representation of the tree.
    //
    std::string to_json(size_t indent_level = 0) override;
};

//
// A module declaration.
//
class module_declaration_t : public node_t {
public:
    //
    // Constructor for a module declaration.
    //
    module_declaration_t(std::unique_ptr<module_header_t> header);

    //
    // Returns a json representation of the tree.
    //
    std::string to_json(size_t indent_level = 0) override;

private:
    std::unique_ptr<module_header_t> _header;

    friend yy::parser;
};

}

#endif // SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
