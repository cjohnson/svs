#ifndef SVS_COMPILER_SV2017_AST_SOURCE_H_
#define SVS_COMPILER_SV2017_AST_SOURCE_H_

#include <memory>
#include <string>
#include <vector>

#include "ast.h"
#include "ast_module_declaration.h"

namespace svs::sv2017::ast {

//
// SystemVerilog 2017 source
//
class source_t : public node_t {
public:
    //
    // Returns a json representation of the tree.
    //
    std::string to_json(size_t indent_level = 0) override;

private:
    std::vector<std::unique_ptr<module_declaration_t>> _descriptions;

    friend yy::parser;
};

}

#endif // SVS_COMPILER_SV2017_AST_SOURCE_H_
