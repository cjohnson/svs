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

#include "ast/source_text.h"
#include "ast/module_ansi_header.h"
#include "ast/module_declaration.h"

namespace svs::sv2017 { class Parser; }
namespace ast = svs::sv2017::ast;
}

%param { svs::sv2017::Parser& prs }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "parser.h"
}

%token macromodule
%token module
%token endmodule

%token <std::string> identifier

%token semicolon
%token left_parenthesis
%token right_parenthesis

%nterm <std::unique_ptr<ast::SourceText>> source_text
%nterm <std::unique_ptr<ast::ModuleDeclaration>> description

%nterm <std::unique_ptr<ast::ModuleDeclaration>> module_declaration
%nterm <std::unique_ptr<ast::ModuleAnsiHeader>> module_ansi_header

%%

%start start;

start : source_text { prs.result_ = std::move($1); }
      ;

source_text : /* empty */
              { $$ = std::make_unique<ast::SourceText>(); }
            | source_text description
              {
                $$ = std::move($1);
                $$->descriptions_.push_back(std::move($2));
              }
            ;

description : module_declaration
              { $$ = std::move($1); }
            ;

module_declaration : module_ansi_header endmodule
                     { $$ = std::make_unique<ast::ModuleDeclaration>(std::move($1)); }
                   ;

module_ansi_header : module_keyword identifier semicolon
                     { $$ = std::make_unique<ast::ModuleAnsiHeader>($2); }
                   ;

module_keyword : module
               | macromodule
               ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}

