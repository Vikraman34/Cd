%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
void yyerror(char*);
int linenum=0;
extern int yylval;
%}

%%
\n {linenum++;}
[ \t]+ ;
int|float|char|double {return DATATYPE;}
while {return WHILE;}
if {return IF;}
else {return ELSE;}
for {return FOR;}                                                       
[0-9]+ {yylval = atoi(yytext); return INTEGER;}
["].+["] {return STRING;}
[a-zA-Z_]+[0-9]*? {return IDENTIFIER;}
[,=;] {return yytext[0];}
"<"|"<="|">"|">="|"=="|"!=" {return RELATIONAL;}
"+"|"-"|"*"|"/" {return ARITHMETIC;}
"++"|"--" {return UNARYOP;}
"(" {return *yytext;}
")" {return *yytext;}
"{" {return *yytext;}
"}" {return *yytext;}
%%

int yywrap (void) 
{
    printf("\nThe given program is syntactically correct.\t\n");
    return 1;
}

void yyerror(char *s)
{
    printf("\nSyntax error at line number %d\n",linenum);
    exit(1);
}
 
int main()
{
    FILE *fp; 
    fp = fopen("input.c","r"); 
    if (fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }
    printf("Given input:\n");
    char c =fgetc(fp);
    while(c!=EOF)
    {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);
    fp = fopen("input.c","r"); 
    yyin = fp;
    yyparse();
    fclose(fp);

    return 0;
}

