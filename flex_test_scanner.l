%option noyywrap
%{
#include "Definitions.h"
%}

/*%option nounput yylineno*/
%%

"name"         return NAME;
"config"       return CONFIG;
"commission"   return COMM;
"serial"       return SERIAL;
"answer"       return ANSWER;
:              return COLON;

[0-9]+         return INTEGER;

[a-zA-Z_][a-zA-Z0-9_]* return IDENTIFIER;

[ \t\n]        ;

[*][^*]*[*]+([^/*][^*]*[*]+)* ;


.              printf("Unexpected command: %s\n", yytext);

%%

