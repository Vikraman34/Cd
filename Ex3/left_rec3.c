#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* get_alpha(char input[20][50],int in)
{
	char nt,*temp;
	strncpy(temp,input[in]+4,strlen(input[in]));
	
	return temp;	
}

char* get_beta(char input[20][50],int in)
{
	char nt,*temp;
	nt=input[in][0];
	while(nt==input[in][0])
		in++;
	in--;
	strncpy(temp,input[in]+3,strlen(input[in]));
	
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
	
	
	char nt,old_nt;
	char alpha[20],beta[20];
	int index=3;
	for(i=0,j=0;i<count;i++)
	{
		nt=input[i][0];
		if(nt==input[i][index])
		{
			strcpy(alpha,get_alpha(input,i));
			strcpy(beta,get_beta(input,i));
			sprintf(update[j],"%c->%s%c\'",nt,beta,nt);
			j++;
			
			sprintf(update[j],"%c\'->%s%c\'|eps",nt,alpha,nt);
			j++;
			
			old_nt=input[i][0];
		}
		else if(old_nt==nt)
			continue;
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

