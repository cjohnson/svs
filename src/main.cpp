#include <iostream>

#include <sv2017/ast_number.h>
#include <sv2017/parser.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "need a file\n";
        return 1;
    }
    svs::sv2017::parser parser;

    std::shared_ptr<svs::sv2017::ast::integral_number_t> number =
        parser.parse(argv[1]);
    if (!number) {
        std::cerr << "Failed to parse\n";
        return 0;
    }

    std::cout << "Found ";
    if (number->is_signed) {
        std::cout << "signed ";
    } else {
        std::cout << "unsigned ";
    }
    std::cout << "hex number ";
    if (number->size.has_value()) {
        std::cout << "(size " << number->size.value() << ") ";
    }
    std::cout << "value " << number->value;
    std::cout << "\n";

    return 0;
}

