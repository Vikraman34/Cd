%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"y.tab.h"
int yylex(void);
void yyerror(char *str);

%}


%token NUMBER ID

%right '=' 

%token AND OR NOT

%left '&' '|'

%token GTE LTE NE EQ

%left '<' '>'
  
%left '+' '-'
  
%left '*' '/'

%right '^'

%left '(' ')'


%%

Assign: A{
	return 0; 
	};

A:Expression
|ID '=' Expression {$1=$3;}
;

Expression: E {
	printf("\nResult=%d\n", $$); 
	return 0; 
	}; 

E:E'+'E {$$=$1+$3;} 

|E'-'E {$$=$1-$3;} 

|E'*'E {$$=$1*$3;} 

|E'/'E {$$=$1/$3;} 

|E'^'E {$$=pow($1,$3);}

|'('E')' {$$=$2;} 
		
|E'<'E {if($1<$3)
		$$=1;
	else
		$$=0;}
		
|E'>'E {if($1>$3)
		$$=1;
	else
		$$=0;}
		
|E'&'E {$$=$1&$3;}

|E'|'E {$$=$1|$3;}

|NUMBER {$$=$1;} 

|NUMBER GTE NUMBER {if($1>=$3)
		$$=1;
	else
		$$=0;}
		
|NUMBER LTE NUMBER {if($1<=$3)
		$$=1;
	else
		$$=0;}
		
|NUMBER EQ NUMBER {if($1==$3)
		$$=1;
	else
		$$=0;}

|NUMBER NE NUMBER {if($1!=$3)
		$$=1;
	else
		$$=0;}

|NUMBER AND NUMBER {if($1&&$3)
		$$=1;
	else
		$$=0;}

|NUMBER OR NUMBER {if($1||$3)
		$$=1;
	else
		$$=0;}

|NOT NUMBER {if(!$2)
		$$=1;
	else
		$$=0;}
; 
  
%%
  
 
void yyerror(char *str)
{ 
   fprintf(stderr,"%s\n",str);
} 


void main() 
{ 
   yyparse(); 
} 
