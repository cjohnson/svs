%{

#include <memory>
#include <string>

int yylex(void);
void yyerror(char const *);

%}

%union
{
    std::shared_ptr<std::string> string_val;
}

%token <string_val> T_Identifier

%%

Identifier : T_Identifier {}

