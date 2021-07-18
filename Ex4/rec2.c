#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int flag=0;

typedef struct
{
	char input[20];
	int in;
}string;

int E(string a);
int Eprime(string a);
int T(string a);
int Tprime(string a);
int F(string a);


int E(string a)
{
	a.in=T(a);
	a.in=Eprime(a);
	return a.in;
}

int Eprime(string a)
{
	if(a.input[a.in]=='+')
	{
		a.in++;
		a.in=T(a);
		a.in=Eprime(a);
	}
	else if(a.input[a.in]=='-')
	{
		a.in++;
		a.in=T(a);
		a.in=Eprime(a);
	}
	return a.in;
}

int T(string a)
{
	a.in=F(a);
	a.in=Tprime(a);
	return a.in;
}

int Tprime(string a)
{
	if(a.input[a.in]=='*')
	{
		a.in++;
		a.in=F(a);
		a.in=Tprime(a);
	}
	else if(a.input[a.in]=='/')
	{
		a.in++;
		a.in=F(a);
		a.in=Tprime(a);
	}
	return a.in;
}

int F(string a)
{
	if(isdigit(a.input[a.in]))
		a.in++;
	else if(a.input[a.in]=='(')
	{
		a.in++;
		a.in=E(a);
		if(a.input[a.in]==')')
		{
			a.in++;	
		}
		else
			flag=1;
	}
	else
		flag=1;

	return a.in;
}

void main()
{
	string a;
	a.in=0;
	printf("Enter the string : ");
	scanf(" %s",a.input);
	
	printf("\nInput : %s\n",a.input);

	a.in=E(a);
	if(a.input[a.in]=='$' && flag==0)
		printf("\nSuccess\n");
	else
		printf("\nError\n");
}
