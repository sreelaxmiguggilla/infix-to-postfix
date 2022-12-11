void push(char);
int prec(char);
char pop();
#include<stdio.h>
#include<string.h>
char stack[10];
int  top=-1;
void main()
{
	char st[10],postfix[10];
	int i,j=0;
	printf("eterstrig");
	scanf("%s",st);
	printf("%s",st);
	for(i=0;st[i]!='\0';i++)
	{
	//	printf("%c",st[i]);
	if(st[i]=='(')	
	push(st[i]);
	else if(st[i]==')')
	{
		while(stack[top]!='(')
		{
		postfix[j]=pop();
		j++;
	    }
	    pop();
	}
	else if(st[i]>='a' && st[i]<='z')
	{
	postfix[j]=st[i];
	j++;
	}
	else
	{
		while(prec(stack[top])>=prec(st[i]))
		{
			postfix[j]=pop();
			j++;
		}
		push(st[i]);
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
