#include<stdio.h>
#include<string.h>
#define n 50

char stack[n];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x;

    x = stack[top];
    top--;

    return x;
}

void main()
{
	char s;
	
	printf("Enter string");
	scanf("%c",&push(stack));
	
	stack.toLoerCase();
	
	for(i=0;i<n;i++)
	{
		if(stack[i] == 'a' || stack[i] == 'e' || stack[i] == 'i' || stack[i] == 'o' || stack[i] == 'u')
		{
			char temp[i]=pop();
			push(temp.strrev());
		}
		
		else
		{
			push(stack[i]);
		}
		
		
	}
	
	
	
	
	
}
