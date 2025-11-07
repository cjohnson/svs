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

#include "ast_source.h"
#include "ast_module_declaration.h"

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

%token MODULE
%token ENDMODULE

%token <std::string> IDENTIFIER

%token SEMICOLON

%nterm <ast::source_t *> source_text

%nterm <ast::module_declaration_t *> description
%nterm <ast::module_declaration_t *> module_declaration
%nterm <ast::module_declaration_t *> module_nonansi_header

%%

%start start;

start : source_text { prs.result = $1; }
      ;

source_text : /* empty */             { $$ = new ast::source_t; }
            | source_text description { ($$ = $1)->add_declaration($2); }
            ;

description : module_declaration { $$ = $1; }
            ;

module_declaration : module_nonansi_header ENDMODULE { $$ = $1; }
                   ;

module_nonansi_header : MODULE IDENTIFIER SEMICOLON { $$ = new ast::module_declaration_t{ $2 }; }
                      ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
