%{

#include <string>

int yylex(void);
void yyerror(char const *);

%}

%code requires {
#include <string>
}

%union {
    std::string *string_val;
}

%token <string_val> T_Identifier

%%

Identifier : T_Identifier {}

