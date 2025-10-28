#include <iostream>
#include <sv2017/parser.h>

int main(void) {
    svs::sv2017::parser parser;
    if (parser.parse() || !parser.result) {
        std::cerr << "Failed to parse\n";
        return 1;
    }

    for (const auto& s : *parser.result) {
        std::cout << "Found Identifier: " << s << "\n";
    }

    return 0;
}
