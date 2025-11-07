#ifndef SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include "ast.h"

namespace svs::sv2017::ast {

//
// A module declaration.
//
class module_declaration_t : public node_t {
public:
    //
    // Constructor for a module declaration.
    //
    module_declaration_t(const std::string& identifier);

    //
    // Returns a json representation of the tree.
    //
    std::string to_json(size_t indent_level = 0) override;

    //
    // The module identifier.
    //
    inline const std::string& identifier() { return _identifier; }

private:
    std::string _identifier;
};

}

#endif // SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
