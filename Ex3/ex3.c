#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
	char alpha[20][50];
	char beta[20];
	int count;
}parse;

parse get_alphabeta(char input[20][50],int in)
{
	parse temp;
	temp.count=0;
	int i,len,x=0,y=0;
	len=strlen(input[in]);
	char nt=input[in][0];
	for(i=3;i<len;i++)
	{
		if(nt==input[in][i])
		{
			y=0;
			i++;
			while(input[in][i]!='|')
			{
				temp.alpha[x][y]=input[in][i];
				i++;
				y++;
			}
			temp.alpha[x][y]='\0';
			x++;
			temp.count++;
		}
		else
		{
			strncpy(temp.beta,input[in]+i,len);
		}
	}
	return temp;	
}


int notin(char update[20][50],int in)
{
	int i;
	for(i=0;i<in;i++)
	{
		if(strcmp(update[i],update[in])==0)
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	char input[20][50];
	char update[20][50];
	int i,j,count,ncount,flag=0;
	printf("Enter the number of productions : ");
	scanf(" %d",&count);
	
	for(i=0;i<count;i++)
	{
		printf("\n %d : ",i+1);
		scanf(" %s",input[i]);	
	}
	
	printf("\n\nGrammar:\n");
	for(i=0;i<count;i++)
	{
		printf(" %d : %s\n",i+1,input[i]);
		if(input[i][0]==input[i][3])
			flag=1;
	}
	
	if(flag==1)
	{
		printf("\nLeft Recursive\n");
		printf("\nEliminating Left recursion\n");
	}
		
	else
		printf("\nNo Left Recursion\n");
	
	
	char nt;
	char alpha[20],beta[20];
	int index=3,a;
	for(i=0,j=0;i<count;i++)
	{
		nt=input[i][0];
		parse temp;
		if(nt==input[i][index])
		{
			temp=get_alphabeta(input,i);
			sprintf(update[j],"%c->%s%c\'",nt,temp.beta,nt);
			j++;
			
			for(a=0;a<temp.count;a++)
			{
				sprintf(update[j],"%c\'->%s%c\'|eps",nt,temp.alpha[a],nt);
				j++;
			}
		}
		else
		{
			strcpy(update[j],input[i]);
			j++;
		}		
		
		ncount=j;
	}
	
	for(i=0,j=0;i<ncount;i++)
	{
		if(notin(update,i))
		{
			printf(" %d : %s\n",j+1,update[i]);
			j++;
		}
	}
	
}

