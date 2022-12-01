%{
    #include "calc.tab.h"    
%}

%option nounput yylineno
%%

"print"     {return print;}
"exit"      {return exit_command;}
[a-zA-Z]    {yylval.id = yytext[0]; return identifier;}
[0-9]+      {yylval.num = atoi(yytext); return number;}
[ \t]       {return 0;}
[\n]        { }
[-+=;]      {return yytext[0];}
.           {ECHO; yyerror("Unknown character");}
%%

int yywrap()
{
    return 1;
}