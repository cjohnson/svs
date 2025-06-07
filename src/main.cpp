#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <vector>

#include "Lexer.h"
#include "lexical_token/LexicalToken.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: svsc <filename>\n";
        return 1;
    }
    std::string file_name{argv[1]};

    std::ifstream file_stream{file_name};
    std::stringstream file_string_stream;
    file_string_stream << file_stream.rdbuf();
    std::string file_buffer{file_string_stream.str()};

    svs::Lexer lexer;
    std::vector<std::unique_ptr<svs::LexicalToken>> tokens = lexer.lex_file(file_buffer);

    std::cout << "Number of lexical tokens found: " << tokens.size() << "\n";
    for (const std::unique_ptr<svs::LexicalToken>& token : tokens)
    {
        std::cout << token->to_string() << "\n";
    }

    return 0;
}
