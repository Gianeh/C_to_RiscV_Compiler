#include <iostream>
#include "Definitions.h"

//using the functions and variables in the C compiled flex file
extern int yylex();
//actual token value
extern char* yytext;
//line number
extern int yylineno;

//a serial array containing the names of the input file
std::string names[] = {"name", "config", "comm", "serial", "answer"};

int main()
{
    //name token and value token
    int ntoken, vtoken;
    //parsing of the first input
    ntoken = yylex();
    while(ntoken)
    {
        //we expect the name token first
        std::cout << "ntoken: " << ntoken << std::endl;
        //step by step parsing of the next input
        ntoken = yylex();

    }
    return 0;
}
