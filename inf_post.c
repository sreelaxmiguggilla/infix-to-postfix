void push(char);
int prec(char);
char pop();
#include<stdio.h>
#include<string.h>
char stack[10];
int  top=-1;
void main()
{
	char infix[10],postfix[10];
	int i,j=0;
	printf("eterstrig");
	scanf("%s",infix);
	
	for(i=0;infix[i]!='\0';i++)
	{
	
	if(infix[i]=='(')	
	push(infix[i]);
	else if(infix[i]==')')
	{
		while(stack[top]!='(')
		{
		postfix[j]=pop();
		j++;
	    }
	    pop();
	}
	else if(infix[i]>='a' && infix[i]<='z')
	{
	postfix[j]=infix[i];
	j++;
	}
	else
	{
		while(prec(stack[top])>=prec(infix[i]))
		{
			postfix[j]=pop();
			j++;
		}
		push(infix[i]);
	}
}
postfix[j]='\0';

printf("%s",postfix);
}
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	char x;
	x=stack[top];
	top--;
	return x;
}
int prec(char ch)
{
	switch(ch)
	{
		case '(':
			case ')':
				return 0;
				break;
				case '+':
					case '-':return 1;
					break;
					case '*':
						case '/':return 2;
						break;
		
	}
}
