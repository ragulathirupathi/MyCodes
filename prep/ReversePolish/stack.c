

#include <stdio.h>
#include "stack.h"

//top<-5<-4<-3<-2<-1

struct node *top = NULL; //top


void pushElement(int element)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(temp)
	{
		temp->element = element;
		temp->next    = NULL;	
		if(top)
		{
			temp->next = top;
			top 	   = temp;		
		}
		else
		{
			top = temp;	
		}
	}
	else
	{
		printf("ERROR-FULL\n");
	}	
}

int popElement(void)
{
	int pop = 0;
	struct node *temp;
	if(top)
	{
		temp = top;
		top  = top->next;
		pop  = temp->element;
		free(temp);
	}
	else
	{
		printf("ERROR-EMPTY\n");
	}
	return pop;

}

void display(void)
{
	struct node *temp = top;
	printf("ELEMENTS-START\n");
	while(temp)
	{
		printf("%d\n",temp->element);
		temp = temp->next;
	
	}
	printf("ELEMENTS-END\n");
}





