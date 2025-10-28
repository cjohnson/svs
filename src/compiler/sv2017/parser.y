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

namespace svs::sv2017 { class parser; }
}

%param { svs::sv2017::parser& prs }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
#include "parser.h"
}

%token <std::string> identifier_k
%token <std::string> system_tf_identifier_k

%nterm <std::shared_ptr<std::vector<std::string>>> identifier_list
%nterm <std::string> identifier

%%

%start description;

description : identifier_list { prs.result = $1; }
            ;

identifier_list : /* empty */                { $$ = std::make_shared<std::vector<std::string>>(); }
                | identifier_list identifier { ($$ = $1)->push_back($2); }
                ;

identifier : identifier_k { $$ = $1; }
           ;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
    std::cerr << l << ": " << m << '\n';
}
