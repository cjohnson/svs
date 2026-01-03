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
#include "ast/attribute.h"
#include "ast/continuous_assign.h"
#include "ast/data_type.h"
#include "ast/decimal_number.h"
#include "ast/description.h"
#include "ast/hex_number.h"
#include "ast/integer_vector_data_type.h"
#include "ast/integer_vector_type.h"
#include "ast/lifetime.h"
#include "ast/module_ansi_header.h"
#include "ast/module_declaration.h"
#include "ast/net_assignment.h"
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
%nterm <std::unique_ptr<ast::TimeunitsDeclaration>>     timeunits_declaration_opt
%nterm <std::unique_ptr<ast::TimeunitsDeclaration>>     timeunit_declaration
%nterm <std::unique_ptr<ast::TimeunitsDeclaration>>     timeprecision_declaration

/* A.1.3 Module parameters and ports */

%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> list_of_port_declarations
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> list_of_port_declarations_opt
%nterm <ast::PortDirection>                                     port_direction
%nterm <std::optional<ast::PortDirection>>                      port_direction_opt
%nterm <std::unique_ptr<ast::VariablePortHeader>>               variable_port_header
%nterm <std::unique_ptr<ast::AnsiPortDeclaration>>              ansi_port_declaration
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> ansi_port_declaration_cs
%nterm <std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>> ansi_port_declaration_cs_opt

/* A.1.4 Module items */

%nterm <std::unique_ptr<ast::ContinuousAssign>>              module_common_item
%nterm <std::unique_ptr<ast::ContinuousAssign>>              module_or_generate_item
%nterm <std::unique_ptr<ast::ContinuousAssign>>              non_port_module_item
%nterm <std::vector<std::unique_ptr<ast::ContinuousAssign>>> non_port_module_items

/* A.2 Declarations */

/* A.2.1.3 Type declarations */

%nterm <ast::Lifetime>                lifetime
%nterm <std::optional<ast::Lifetime>> lifetime_opt

/* A.2.2 Declaration data types */

/* A.2.2.1 Net and variable types */

%nterm <std::unique_ptr<ast::DataType>> data_type
%nterm <ast::IntegerVectorType>         integer_vector_type
%nterm <std::unique_ptr<ast::DataType>> variable_port_type
%nterm <std::unique_ptr<ast::DataType>> var_data_type

/* A.6 Behavioral statements */

/* A.6.1 Continuous assignment and net alias statements */

%nterm <std::unique_ptr<ast::ContinuousAssign>>           continuous_assign
%nterm <std::vector<std::unique_ptr<ast::NetAssignment>>> list_of_net_assignments
%nterm <std::unique_ptr<ast::NetAssignment>>              net_assignment

/* A.8.3 Expressions */

%nterm <std::unique_ptr<ast::Expression>> constant_expression
%nterm <std::unique_ptr<ast::Expression>> expression

/* A.8.4 Primaries */

%nterm <std::unique_ptr<ast::Expression>>  constant_primary
%nterm <std::unique_ptr<ast::Expression>>  primary
%nterm <std::unique_ptr<ast::Expression>>  primary_literal
%token <std::unique_ptr<ast::TimeLiteral>> time_literal

/* A.8.5 Expression left-side values */

%nterm <std::string> net_lvalue

/* A.8.7 Numbers */

%nterm <std::unique_ptr<ast::Expression>>     number
%nterm <std::unique_ptr<ast::IntegralNumber>> integral_number
%nterm <std::unique_ptr<ast::DecimalNumber>>  decimal_number
%nterm <std::unique_ptr<ast::HexNumber>>      hex_number
%token <std::string>                          unsigned_number
%token <std::string>                          hex_value
%token <ast::Signedness>                      hex_base

/* A.9.1 Attributes */

%nterm <std::vector<std::unique_ptr<ast::Attribute>>> attribute_instance
%nterm <std::vector<std::unique_ptr<ast::Attribute>>> attribute_instances
%nterm <std::unique_ptr<ast::Attribute>>              attr_spec
%nterm <std::vector<std::unique_ptr<ast::Attribute>>> attr_spec_cs
%nterm <std::string>                                  attr_name

/* A.9.3 Identifiers */

%token <std::string> identifier
%nterm <std::string> module_identifier
%nterm <std::string> net_identifier
%nterm <std::string> port_identifier
%nterm <std::string> ps_or_hierarchical_net_identifier

/* Annex B: Keywords */

%token assign
%token automatic
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
%token static_
%token timeprecision
%token timeunit

/* Additional operator tokens */

%token attribute_instance_begin
%token attribute_instance_end
%token comma
%token equals
%token forward_slash
%token left_parenthesis
%token right_parenthesis
%token semicolon

%%

%start start;

start : source_text { prs.result_ = std::move($1); }
      ;

/* A.1 Source text */

/* A.1.2 SystemVerilog source text */

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

module_ansi_header : attribute_instances module_keyword lifetime_opt module_identifier
                     list_of_port_declarations_opt semicolon
                     {
                       const yy::location location{ @1.begin, @6.end };
                       $$ = std::make_unique<ast::ModuleAnsiHeader>(location, std::move($1), $3, std::move($4), std::move($5));
                     }
                   ;

module_declaration : module_ansi_header timeunits_declaration_opt non_port_module_items endmodule
                     {
                       const yy::location location{ @1.begin, @3.end };
                       $$ = std::make_unique<ast::ModuleDeclaration>(
                         location, std::move($1), std::move($2), std::move($3));
                     }
                   ;

module_keyword : module | macromodule ;

timeunits_declaration : timeunit_declaration      { $$ = std::move($1); }
                      | timeprecision_declaration { $$ = std::move($1); }
                      ;

timeunits_declaration_opt : /* empty */
                            { $$ = nullptr; }
                          | timeunits_declaration
                            { $$ = std::move($1); }
                          ;

timeunit_declaration : timeunit time_literal semicolon
                       {
                         const yy::location location{ @1.begin, @3.end };
                         $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($2), nullptr);
                       }
                     | timeunit time_literal forward_slash time_literal semicolon
                       {
                         const yy::location location{ @1.begin, @5.end };
                         $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($2), std::move($4));
                       }
                     | timeunit time_literal semicolon timeprecision time_literal semicolon
                       {
                         const yy::location location{ @1.begin, @6.end };
                         $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($2), std::move($5));
                       }
                     ;

timeprecision_declaration : timeprecision time_literal semicolon
                            {
                              const yy::location location{ @1.begin, @3.end };
                              $$ = std::make_unique<ast::TimeunitsDeclaration>(location, nullptr, std::move($2));
                            }
                          | timeprecision time_literal semicolon timeunit time_literal semicolon
                            {
                              const yy::location location{ @1.begin, @6.end };
                              $$ = std::make_unique<ast::TimeunitsDeclaration>(location, std::move($5), std::move($2));
                            }
                          ;

/* A.1.3 Module parameters and ports */

list_of_port_declarations : left_parenthesis ansi_port_declaration_cs_opt right_parenthesis
                            { $$ = std::move($2); }
                          ;

list_of_port_declarations_opt : /* empty */
                                { $$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>(); }
                              | list_of_port_declarations
                                { $$ = std::move($1); }
                              ;

port_direction : input  { $$ = ast::PortDirection::kInput; }
               | output { $$ = ast::PortDirection::kOutput; }
               | inout  { $$ = ast::PortDirection::kInout; }
               | ref    { $$ = ast::PortDirection::kRef; }
               ;

port_direction_opt : /* empty */    { $$ = std::nullopt; }
                   | port_direction { $$ = $1; }
                   ;

variable_port_header : port_direction_opt variable_port_type
                       {
                         const yy::location location{ @1.begin, @2.end };
                         $$ = std::make_unique<ast::VariablePortHeader>(location, std::move($1), std::move($2));
                       }
                     ;

ansi_port_declaration : variable_port_header port_identifier
                        {
                          const yy::location location{ @1.begin, @2.end };
                          $$ = std::make_unique<ast::AnsiPortDeclaration>(location, std::move($1), std::move($2));
                        }
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

ansi_port_declaration_cs_opt : /* empty */
                               { $$ = std::vector<std::unique_ptr<ast::AnsiPortDeclaration>>(); }
                             | ansi_port_declaration_cs
                               { $$ = std::move($1); }
                             ;

/* A.1.4 Module items */

module_common_item : continuous_assign { $$ = std::move($1); }
                   ;

module_or_generate_item : attribute_instances module_common_item { $$ = std::move($2); }
                        ;

non_port_module_item : module_or_generate_item { $$ = std::move($1); }
                     ;

non_port_module_items : /* empty */
                        { $$ = std::vector<std::unique_ptr<ast::ContinuousAssign>>(); }
                      | non_port_module_items non_port_module_item
                        {
                          $1.push_back(std::move($2));
                          $$ = std::move($1);
                        }
                      ;

/* A.2 Declarations */

/* A.2.1.3 Type declarations */

lifetime : static_   { $$ = ast::Lifetime::kStatic; }
         | automatic { $$ = ast::Lifetime::kAutomatic; }
         ;

lifetime_opt : /* empty */ { $$ = std::nullopt; }
             | lifetime    { $$ = $1; }
             ;

/* A.2.2 Declaration data types */

/* A.2.2.1 Net and variable types */

data_type : integer_vector_type
            { $$ = std::make_unique<ast::IntegerVectorDataType>(@1, std::move($1)); }
          ;

integer_vector_type : bit   { $$ = ast::IntegerVectorType::kBit; }
                    | logic { $$ = ast::IntegerVectorType::kLogic; }
                    | reg   { $$ = ast::IntegerVectorType::kReg; }
                    ;

variable_port_type : var_data_type { $$ = std::move($1); }
                   ;

var_data_type : data_type { $$ = std::move($1); }
              ;

/* A.6 Behavioral statements */

/* A.6.1 Continuous assignment and net alias statements */

continuous_assign : assign list_of_net_assignments semicolon
                    {
                      const yy::location& location{ @1.begin, @3.end };
                      $$ = std::make_unique<ast::ContinuousAssign>(location, std::move($2));
                    }
                  ;

list_of_net_assignments : net_assignment
                          {
                            $$ = std::vector<std::unique_ptr<ast::NetAssignment>>();
                            $$.push_back(std::move($1));
                          }
                        | list_of_net_assignments comma net_assignment
                          {
                            $1.push_back(std::move($3));
                            $$ = std::move($1);
                          }
                        ;

net_assignment : net_lvalue equals expression
                 {
                   const yy::location location{ @1.begin, @3.end };
                   $$ = std::make_unique<ast::NetAssignment>(location, std::move($1), std::move($3));
                 }
               ;

/* A.8.3 Expressions */

constant_expression : constant_primary { $$ = std::move($1); }
                    ;

expression : primary { $$ = std::move($1); }
           ;

/* A.8.4 Primaries */

constant_primary : primary_literal { $$ = std::move($1); }
                 ;

primary : primary_literal { $$ = std::move($1); }
        ;

primary_literal : number { $$ = std::move($1); }
                ;

/* A.8.5 Expression left-side values */

net_lvalue : ps_or_hierarchical_net_identifier { $$ = std::move($1); }
           ;

/* A.8.7 Numbers */

number : integral_number { $$ = std::move($1); }
       ;

integral_number : hex_number     { $$ = std::move($1); }
                | decimal_number { $$ = std::move($1); }
                ;

decimal_number : unsigned_number
                 {
                   $$ = std::make_unique<ast::DecimalNumber>(
                     @1, std::nullopt, ast::Signedness::kSigned, std::move($1));
                 }
               ;

hex_number : hex_base hex_value
             {
               const yy::location location{ @1.begin, @2.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::nullopt, std::move($1), std::move($2));
             }
           | unsigned_number hex_base hex_value
             {
               const yy::location location{ @1.begin, @3.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::move($1), std::move($2), std::move($3));
             }
           | hex_base unsigned_number
             {
               const yy::location location{ @1.begin, @2.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::nullopt, std::move($1), std::move($2));
             }
           | unsigned_number hex_base unsigned_number
             {
               const yy::location location{ @1.begin, @3.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::move($1), std::move($2), std::move($3));
             }
           | hex_base identifier
             {
               const yy::location location{ @1.begin, @2.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::nullopt, std::move($1), std::move($2));
             }
           | unsigned_number hex_base identifier
             {
               const yy::location location{ @1.begin, @3.end };
               $$ = std::make_unique<ast::HexNumber>(location, std::move($1), std::move($2), std::move($3));
             }
           ;

/* A.9.1 Attributes */

attribute_instance : attribute_instance_begin attr_spec_cs attribute_instance_end { $$ = std::move($2); }
                   ;

attribute_instances : /* empty */
                      { $$ = std::vector<std::unique_ptr<ast::Attribute>>(); }
                    | attribute_instances attribute_instance
                      {
                        for (std::unique_ptr<ast::Attribute>& attribute : $2)
                          $1.push_back(std::move(attribute));
                        $$ = std::move($1);
                      }
                    ;

attr_spec : attr_name
            { $$ = std::make_unique<ast::Attribute>(@1, std::move($1), nullptr); }
          | attr_name equals constant_expression
            {
              const yy::location location{ @1.begin, @3.end };
              $$ = std::make_unique<ast::Attribute>(location, std::move($1), std::move($3));
            }
          ;

attr_spec_cs : attr_spec
               {
                 $$ = std::vector<std::unique_ptr<ast::Attribute>>();
                 $$.push_back(std::move($1));
               }
             | attr_spec_cs comma attr_spec
               {
                 $1.push_back(std::move($3));
                 $$ = std::move($1);
               }
             ;

attr_name : identifier ;

/* A.9.3 Identifiers */

module_identifier : identifier ;

net_identifier : identifier ;

port_identifier : identifier ;

ps_or_hierarchical_net_identifier : net_identifier ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}

