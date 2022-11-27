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
        //we expect the colon next , else throw an error
        if(yylex() != COLON)
        {
            std::cout << "Syntax error in line " << yylineno << ": expected ':', got " << yytext << std::endl;
            return 1;
        }
        vtoken = yylex();
        switch(ntoken){
            case NAME:
            case CONFIG:
            case COMM:
                if (vtoken != IDENTIFIER)
                {
                    std::cout << "Syntax error in line " << yylineno << ": expected identifier, got " << yytext << std::endl;
                    return 1;
                }
                //print the name and value
                std::cout << names[ntoken - 1] << ": " << yytext << std::endl;
            case SERIAL:
                if (vtoken != IDENTIFIER)
                {
                    std::cout << "Syntax error in line " << yylineno << ": expected EX, got " << yytext << std::endl;
                    return 1;
                }
                //print the name and value
                std::cout << names[ntoken - 1] << ": " << yytext << std::endl;
            case ANSWER:
                if (vtoken != INTEGER)
                {
                    std::cout << "Syntax error in line " << yylineno << ": expected integer, got " << yytext << std::endl;
                    return 1;
                }
                //print the name and value
                std::cout << names[ntoken - 1] << ": " << yytext << std::endl;
            default:
                std::cout << "Syntax error in line " << yylineno << std::endl;
                return 1;
        }
        //step by step parsing of the next input
        ntoken = yylex();

    }
    return 0;
}
