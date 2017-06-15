#include<stdio.h>

char stack[100]={0};
int top = -1;

int precedence(char ch)
{

	switch(ch)
	{
		case '+':
		case '-':
			return(1);
		case '*':
		case '/':
			return(2);
	}
	return(-1);
}

int isempty()
{
	if(top== -1)
		return(1);
	else
		return(0);
}


void push(char x)
{
	if(isempty())
		top++;

	stack[top]=x;
	top++;
}

char pop()
{
	char x;
	x = stack[top];
	top--;
	return(x);
}

int isoperand(char ch)
{
	if((ch >= 'a' && ch <= 'z' ) ||(ch >= 'A' && ch <= 'Z'))
		return(1);
	else
		return(0);
}

void infix_to_postfix(char infix_exp[],char postfix_exp[])
{
	int i,k;
	k=0;
	for(i=0;infix_exp[i] != '\0';i++)
	{
		if(isoperand(infix_exp[i]))
		{
			postfix_exp[k]=infix_exp[i];
			k++;
		}
		else {   // for operator and brackets i.e. +,-,*,/,(, ) 
			if(infix_exp[i] == ')')
			{
				while(!isempty() && stack[top] != '(')
				{
					postfix_exp[k] = pop();
					k++;
				}
				pop(); // remove '(' from stack
			}
			else if(infix_exp[i] == '(')
				push(infix_exp[i]);
			else{
				while(!isempty() && precedence(infix_exp[i]) <= precedence(stack[top]))
				{
					postfix_exp[k] = pop();
					k++;
				}
				push(infix_exp[i]);
			}
		}
	}
	while(!isempty())
		postfix_exp[k++] = pop();

	postfix_exp[k] = '\0';
}


int main()
{
	char infix_exp[50]="a+b*(c*d-e)*(f+g*h)-i";
	char postfix_exp[50]={0};
	printf("infix --> %s\n",infix_exp);

	infix_to_postfix(infix_exp,postfix_exp);

	printf("infix --> %s\n",infix_exp);
	printf("postfix --> %s\n",postfix_exp);

	return(0);
}

