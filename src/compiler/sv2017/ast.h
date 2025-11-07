#ifndef SVS_COMPILER_SV2017_AST_H_
#define SVS_COMPILER_SV2017_AST_H_

#include <string>

namespace svs::sv2017::ast {

//
// SystemVerilog 2017 AST node
//
class node_t {
public:
    //
    // Returns a json representation of the tree.
    //
    virtual std::string to_json(size_t indent_level = 0) = 0;

protected:
    //
    // Appends indentation and returns the ostream.
    //
    std::ostream& with_indent(std::ostream& os, size_t indent_level);
};

}

#endif // SVS_COMPILER_SV2017_AST_H_
