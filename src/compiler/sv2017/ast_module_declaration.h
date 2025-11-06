#ifndef SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <iostream>
#include <vector>

namespace svs::sv2017::ast {

//
// A module declaration.
//
class module_declaration_t {
public:
    void print() {
        std::cout << "Module\n";
    }
};

//
// SystemVerilog source
//
class ast_t {
public:
    ast_t(module_declaration_t *module) {
        descriptions.push_back(module);
    }

    ~ast_t() {
        for (const auto& declaration : descriptions)
            delete declaration;
    }

    void print() {
        for (const auto& declaration : descriptions)
            declaration->print();
    }

private:
    std::vector<module_declaration_t *> descriptions;
};


}

#endif // SVS_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
