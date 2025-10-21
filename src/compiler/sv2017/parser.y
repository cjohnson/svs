%{

#include <string>

int yylex(void);
void yyerror(char const *);

%}

%code requires {
#include <string>
}

%union {
    std::string *string;
}

%token <string_val> identifier_k
%token <string_val> system_tf_identifier_k

%%

Identifier : identifier_k {}

