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
#include <optional>
#include <string>
#include <vector>

#include "ast/ansi_port_declaration.h"
#include "ast/data_type.h"
#include "ast/description.h"
#include "ast/integer_vector_data_type.h"
#include "ast/integer_vector_type.h"
#include "ast/module_ansi_header.h"
#include "ast/module_declaration.h"
#include "ast/port_direction.h"
#include "ast/source_text.h"
#include "ast/variable_port_header.h"

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

/* Annex A: Formal syntax */

/* A.1.2 SystemVerilog source text */

%nterm <std::unique_ptr<ast::SourceText>>               source_text
%nterm <std::unique_ptr<ast::Description>>              description
%nterm <std::vector<std::unique_ptr<ast::Description>>> descriptions
%nterm <std::unique_ptr<ast::ModuleAnsiHeader>>         module_ansi_header
%nterm <std::unique_ptr<ast::ModuleDeclaration>>        module_declaration
%nterm                                                  module_keyword

/* A.1.3 Module parameters and ports */

%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> list_of_port_declarations
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> list_of_port_declarations_opt
%nterm <ast::PortDirection>                                     port_direction
%nterm <std::optional<ast::PortDirection>>                      port_direction_opt
%nterm <std::unique_ptr<ast::VariablePortHeader>>               variable_port_header
%nterm <std::unique_ptr<ast::AnsiPortDeclaration>>              ansi_port_declaration
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> ansi_port_declaration_cs
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> ansi_port_declaration_cs_opt

/* A.2.2 Declaration data types */

/* A.2.2.1 Net and variable types */

%nterm <std::unique_ptr<ast::DataType>> data_type
%nterm <ast::IntegerVectorType>         integer_vector_type
%nterm <std::unique_ptr<ast::DataType>> variable_port_type
%nterm <std::unique_ptr<ast::DataType>> var_data_type

/* A.9.3 Identifiers */

%token <std::string> identifier
%nterm <std::string> module_identifier
%nterm <std::string> port_identifier

/* Annex B: Keywords */

%token bit
%token endmodule
%token inout
%token input
%token logic
%token macromodule
%token module
%token output
%token ref
%token reg

/* Additional operator tokens */

%token comma
%token left_parenthesis
%token right_parenthesis
%token semicolon

%%

%start start;

start : source_text { prs.result_ = std::move($1); }
      ;

source_text : descriptions { $$ = std::make_unique<ast::SourceText>(std::move($1)); } ;

description : module_declaration { $$ = std::move($1); } ;

descriptions : /* empty */
               { $$ = std::vector<std::unique_ptr<ast::Description>>(); }
             | descriptions description
               { ($$ = std::move($1)).push_back(std::move($2)); }

module_declaration : module_ansi_header endmodule
                     { $$ = std::make_unique<ast::ModuleDeclaration>(std::move($1)); }
                   ;

module_ansi_header : module_keyword module_identifier list_of_port_declarations_opt semicolon
                     { $$ = std::make_unique<ast::ModuleAnsiHeader>(std::move($2), std::move($3)); }
                   ;

list_of_port_declarations_opt : /* empty */
                                { $$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>(); }
                              | list_of_port_declarations
                                { $$ = std::move($1); }
                              ;

list_of_port_declarations : left_parenthesis ansi_port_declaration_cs_opt right_parenthesis
                            { $$ = std::move($2); }
                          ;

ansi_port_declaration_cs_opt : /* empty */
                               { $$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>(); }
                             | ansi_port_declaration_cs
                               { $$ = std::move($1); }
                             ;

ansi_port_declaration_cs : ansi_port_declaration
                           { ($$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>()).push_back(std::move($1)); }
                         | ansi_port_declaration_cs comma ansi_port_declaration
                           { ($$ = std::move($1)).push_back(std::move($3)); }
                         ;

ansi_port_declaration : variable_port_header port_identifier
                        { $$ = std::make_unique<ast::AnsiPortDeclaration>(std::move($1), std::move($2)); }
                      ;

variable_port_header : port_direction_opt variable_port_type
                       { $$ = std::make_unique<ast::VariablePortHeader>(std::move($1), std::move($2)); }
                     ;

variable_port_type : var_data_type { $$ = std::move($1); }
                   ;

var_data_type : data_type { $$ = std::move($1); }
              ;

data_type : integer_vector_type
            { $$ = std::make_unique<ast::IntegerVectorDataType>(std::move($1)); }
          ;

integer_vector_type : bit   { $$ = ast::IntegerVectorType::kBit; }
                    | logic { $$ = ast::IntegerVectorType::kLogic; }
                    | reg   { $$ = ast::IntegerVectorType::kReg; }
                    ;

port_direction_opt : /* empty */    { $$ = std::nullopt; }
                   | port_direction { $$ = $1; }
                   ;

port_direction : input  { $$ = ast::PortDirection::kInput; }
               | output { $$ = ast::PortDirection::kOutput; }
               | inout  { $$ = ast::PortDirection::kInout; }
               | ref    { $$ = ast::PortDirection::kRef; }
               ;

module_keyword : module | macromodule ;

module_identifier : identifier ;

port_identifier : identifier ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}

