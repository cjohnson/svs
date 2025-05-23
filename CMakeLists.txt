cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(svs LANGUAGES CXX)

add_executable(svsc
    ./src/main.cpp
    ./src/FilePosition.cpp
    ./src/Lexer.cpp

    ./src/lexical_token/LexicalToken.cpp
    ./src/lexical_token/WhiteSpaceLexicalToken.cpp
    ./src/lexical_token/CommentLexicalToken.cpp
    ./src/lexical_token/OperatorLexicalToken.cpp)
