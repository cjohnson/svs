%{

#include <string>

%}

%language "c++"

%skeleton "lalr1.cc"
%require "3.8.1"
%header

%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#include <memory>
#include <string>
#include <vector>

#include "ast_number.h"

namespace svs::sv2017 { class parser; }
namespace ast = svs::sv2017::ast;
}

%param { svs::sv2017::parser& prs }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "parser.h"
}

%token <std::string> INTEGRAL_NUMBER_VALUE

%token <bool> DECIMAL_BASE
%token <bool> BINARY_BASE
%token <bool> OCTAL_BASE
%token <bool> HEX_BASE

%token <std::string> STRING_LITERAL

%token <std::string> IDENTIFIER
%token <std::string> SYSTEM_TF_IDENTIFIER

%nterm <std::shared_ptr<ast::integral_number_t>> integral_number
%nterm <std::shared_ptr<ast::integral_number_t>> octal_number
%nterm <std::shared_ptr<ast::integral_number_t>> hex_number

%%

%start description;

description : integral_number { prs.result = $1; }
            ;

integral_number : octal_number
                | hex_number
                ;

octal_number : OCTAL_BASE INTEGRAL_NUMBER_VALUE               { $$ = std::make_shared<ast::integral_number_t>(ast::integral_number_t::type_t::Octal, $1, $2); }
             | INTEGRAL_NUMBER_VALUE OCTAL_BASE INTEGRAL_NUMBER_VALUE { $$ = std::make_shared<ast::integral_number_t>($1, ast::integral_number_t::type_t::Octal, $2, $3); }
             ;

hex_number : HEX_BASE INTEGRAL_NUMBER_VALUE               { $$ = std::make_shared<ast::integral_number_t>(ast::integral_number_t::type_t::Hex, $1, $2); }
           | INTEGRAL_NUMBER_VALUE HEX_BASE INTEGRAL_NUMBER_VALUE { $$ = std::make_shared<ast::integral_number_t>($1, ast::integral_number_t::type_t::Hex, $2, $3); }
           ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
