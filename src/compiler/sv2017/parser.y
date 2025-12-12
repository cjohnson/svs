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
#include "ast/time_literal.h"
#include "ast/timeunits_declaration.h"
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

/* A.1 Source text */

/* A.1.2 SystemVerilog source text */

%nterm <std::unique_ptr<ast::SourceText>>               source_text
%nterm <std::unique_ptr<ast::Description>>              description
%nterm <std::vector<std::unique_ptr<ast::Description>>> descriptions
%nterm <std::unique_ptr<ast::ModuleAnsiHeader>>         module_ansi_header
%nterm <std::unique_ptr<ast::ModuleDeclaration>>        module_declaration
%nterm                                                  module_keyword
%nterm <std::unique_ptr<ast::TimeunitsDeclaration>>     timeunits_declaration
%nterm <std::unique_ptr<ast::TimeLiteral>>              time_unit_suffix
%nterm <std::unique_ptr<ast::TimeLiteral>>              time_precision_suffix
%nterm <std::unique_ptr<ast::TimeunitsDeclaration>>     timeunits_declaration_opt

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

/* A.8.4 Primaries */

%token <std::unique_ptr<ast::TimeLiteral>> time_literal

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
%token timeprecision
%token timeunit

/* Additional operator tokens */

%token comma
%token forward_slash
%token left_parenthesis
%token right_parenthesis
%token semicolon

%%

%start start;

start : source_text { prs.result_ = std::move($1); }
      ;

source_text : timeunits_declaration_opt descriptions
              {
                const yy::location location{ @1.begin, @2.end }; 
                $$ = std::make_unique<ast::SourceText>(location, std::move($1), std::move($2));
              }
            ;

description : module_declaration { $$ = std::move($1); } ;

descriptions : /* empty */
               { $$ = std::vector<std::unique_ptr<ast::Description>>(); }
             | descriptions description
               {
                 $1.push_back(std::move($2));
                 $$ = std::move($1);
               }

module_declaration : module_ansi_header timeunits_declaration_opt endmodule
                     {
                       const yy::location location{ @1.begin, @3.end };
                       $$ = std::make_unique<ast::ModuleDeclaration>(location, std::move($1), std::move($2));
                     }
                   ;

module_ansi_header : module_keyword module_identifier list_of_port_declarations_opt semicolon
                     {
                       const yy::location location{ @1.begin, @4.end };
                       $$ = std::make_unique<ast::ModuleAnsiHeader>(location, std::move($2), std::move($3));
                     }
                   ;

timeunits_declaration : timeunit time_literal semicolon
                        {
                          const yy::location location{ @1.begin, @3.end };
                          $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($2), nullptr);
                        }
                      | timeunit time_literal time_precision_suffix semicolon
                        {
                          const yy::location location{ @1.begin, @4.end };
                          $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($2), std::move($3));
                        }
                      | timeprecision time_literal time_unit_suffix
                        {
                          const yy::location location{ @1.begin, @3.end };
                          $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($3), std::move($2));
                        }
                      ;

time_unit_suffix : semicolon                                 { $$ = nullptr; }
                 | semicolon timeunit time_literal semicolon { $$ = std::move($3); }
                 ;

time_precision_suffix : forward_slash time_literal { $$ = std::move($2); }
                      | timeprecision time_literal { $$ = std::move($2); }
                      ;


timeunits_declaration_opt : /* empty */
                            { $$ = nullptr; }
                          | timeunits_declaration
                            { $$ = std::move($1); }
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
                           {
                             $$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>();
                             $$.push_back(std::move($1));
                           }
                         | ansi_port_declaration_cs comma ansi_port_declaration
                           {
                             $1.push_back(std::move($3));
                             $$ = std::move($1);
                           }
                         ;

ansi_port_declaration : variable_port_header port_identifier
                        {
                          const yy::location location{ @1.begin, @2.end };
                          $$ = std::make_unique<ast::AnsiPortDeclaration>(location, std::move($1), std::move($2));
                        }
                      ;

variable_port_header : port_direction_opt variable_port_type
                       {
                         const yy::location location{ @1.begin, @2.end };
                         $$ = std::make_unique<ast::VariablePortHeader>(location, std::move($1), std::move($2));
                       }
                     ;

variable_port_type : var_data_type { $$ = std::move($1); }
                   ;

var_data_type : data_type { $$ = std::move($1); }
              ;

data_type : integer_vector_type
            { $$ = std::make_unique<ast::IntegerVectorDataType>(@1, std::move($1)); }
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

