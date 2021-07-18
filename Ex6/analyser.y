%{
#include <stdio.h>     
#include <stdlib.h>
#include <ctype.h>
void yyerror(char*);
int yylex(void);
#include "y.tab.h"
%}

%token INTEGER STRING IDENTIFIER RELATIONAL WHILE FOR ARITHMETIC UNARYOP DATATYPE IF ELSE

%%
PROGRAM: LINE
LINE: LINE STATEMENT | STATEMENT

STATEMENT: DATATYPE STATEMENTLIST ';'           
            | STATEMENTLIST  ';'
            | condition_st

STATEMENTLIST: STATEMENTLIST ',' INIT | INIT

INIT: IDENTIFIER | EXPR

EXPR: IDENTIFIER '=' ASSIGNMENTEXPR | IDENTIFIER UNARYOP | IDENTIFIER '=' ARITHMETIC ASSIGNMENTEXPR 

ASSIGNMENTEXPR: IDENTIFIER ARITHMETIC ASSIGNMENTEXPR
                | INTEGER ARITHMETIC ASSIGNMENTEXPR
                | IDENTIFIER UNARYOP
                | IDENTIFIER
                | INTEGER 
                | STRING

condition_st: WHILE '(' condition_expr ')' 
                | WHILE '(' condition_expr ')'  '{' LINE  '}'
                | IF '(' condition_expr ')' LINE ELSE 
                | IF '(' condition_expr ')'  '{' LINE '}' ELSE  '{' LINE  '}'
                | IF '(' condition_expr ')'   ELSE  '{' LINE  '}'
                | IF '(' condition_expr ')'  '{' LINE '}' ELSE  
                | FOR '('DATATYPE IDENTIFIER '='  INTEGER  ';' condition_expr ';' EXPR ')' '{' LINE  '}'
                | FOR '(' DATATYPE IDENTIFIER '='  INTEGER ';' condition_expr ';' EXPR ')'

condition_expr: IDENTIFIER RELATIONAL condition_expr 
                | INTEGER   RELATIONAL condition_expr 
                | IDENTIFIER
                | INTEGER
%%

