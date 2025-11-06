#include <iostream>
#include <memory>

#include <sv2017/ast_number.h>
#include <sv2017/parser.h>

#include "sv2017/ast_module_declaration.h"

using namespace svs::sv2017;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "need a file\n";
        return 1;
    }

    svs::sv2017::parser parser;

    auto ast = std::unique_ptr<ast::ast_t>(parser.parse(argv[1]));
    ast->print();

    return 0;
}

