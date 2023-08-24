#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
int expression(char **pstring, int tokenSize)
{
	char *pdata ;
	int  index    = 0;
	char operator = 0;
	int  element  = 0;
	int  first, second,result = 0;
	for(index = 0; index < tokenSize; index++)
	{
		pdata = pstring[index];
		if(strstr("+",pdata))
			operator = '+';
		else if(strstr("-",pdata))
			operator = '-';
		else if(strstr("*",pdata))
			operator = '*';
		else if(strstr("/",pdata))
			operator = '/';
		else
			operator = '0';
		switch( operator )
		{
			case '0':
			{
				element = atoi(pdata);
				pushElement(element);
				break;	
			}
			case '+':
			{
				first = popElement();
				second = popElement();	
				result = first + second;
				pushElement(result);
				break;			
			}
			case '-':
			{
				first = popElement();
				second = popElement();	
				result = first - second;
				pushElement(result);
				break;			
			}
			case '*':
			{
				first = popElement();
				second = popElement();	
				result = first * second;
				pushElement(result);
				break;			
			}
			case '/':
			{
				first = popElement();
				second = popElement();	
				result = first / second;
				pushElement(result);
				break;			
			}
			default:
				break;
		}
	}
	return popElement();

}



int main(void)
{
	int choice;
	int num;
	
	char *pTring[] = {"2", "1", "+", "3", "*"};
	printf("RESULT = %d\n", expression(pTring,5));
	exit(0);
label:
	printf("Enter choice 1. push 2. pop 3. display\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			printf("Enter element\n");
			scanf("%d",&num);
			pushElement(num);
			break;
		}
		case 2:
		{
			printf("poped element = %d\n", popElement());
			break;
		}
		case 3:
		{
			display();
			break;
		}
		default:
			break;
	}
	goto label;	
	return 0;	

}
