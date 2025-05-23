cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(svs LANGUAGES CXX)

add_executable(svsc
    src/main.cpp
    src/FilePosition.cpp
    src/Lexer.cpp
    src/lexical_token/LexicalToken.cpp)
