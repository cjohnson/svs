#include <iostream>
#include <sv2017/parser.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "need a file\n";
        return 1;
    }
    svs::sv2017::parser parser;

    std::shared_ptr<std::vector<std::string>> result = parser.parse(argv[1]);
    if (!result) {
        std::cerr << "Failed to parse\n";
        return 1;
    }

    for (const auto& s : *result) {
        std::cout << "Found Identifier: " << s << "\n";
    }

    return 0;
}
