#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Lexer.h"

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
    std::vector<svs::LexicalToken *> tokens;
    lexer.lex_file(file_buffer, tokens);

    std::cout << "Number of lexical tokens found: " << tokens.size() << "\n";
    for (svs::LexicalToken *token : tokens)
    {
        if (token->type() != svs::LexicalTokenType::WhiteSpace)
        {
            std::cout << token->to_string() << "\n";
        }
        delete token;
    }

    return 0;
}
