#include <iostream>
#include <memory>

#include <sv2017/parser.h>

using namespace svs::sv2017;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "need a file\n";
        return 1;
    }

    svs::sv2017::parser parser;

    std::unique_ptr<ast::source_t> ast = parser.parse(argv[1]);
    if (ast)
        std::cout << ast->to_json() << '\n';

    return 0;
}

