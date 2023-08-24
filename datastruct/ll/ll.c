#include "ll.h"
#include <stdio.h>
#include <stdlib.h>


Node*  CrateNode(void)
{

	Node* newNode = (Node*) malloc(sizeof(Node));
	if(newNode == NULL)
	{
		printf("can not allocate memory\r\n");
		exit(0);
	}
	return newNode;
}


void PutDataInNode(Node *node, int data)
{
	if( NULL == node )
	{
		printf("node passed null\r\n");
		exit(0);
	}
	else
	{
		node->element = data;
	}

}



//Forms the linked list from STDIN
//example: HEAD-->1-->2-->3-->NULL
//Here 1 is enetered first
void FormLinkedList(Node **list, int n)
{
	Node  *newNode = NULL,*temp = NULL;
	int i = 0,read = 0;
	printf("Using STDIO for forming linked list\r\n");
	for ( i= 0; i < n ; i++ )
	{
			printf("Enter the element of node %d\n", i);
			scanf("%d", &read);
			newNode = CrateNode();
			PutDataInNode(newNode,read);
			if ( i == 0 )
			{
				temp   = newNode;
				*list  = temp;
			
			}
			else
			{
				temp->next = newNode;
				temp = newNode;
			}
		
	}
	
}



void DisplayLinkedList(Node *list)
{

	if ( list == NULL )
	{
		printf (" Enter list is empty\r\n");
	}
	else
	{
		printf("\n HEAD->");
		while ( list )
		{
			printf("%d->",list->element);
			list = list->next;
		}
		printf("NULL\n");
	}
}

int LengthOfLinkedList ( Node *list )
{
	int length = 0;
	while ( list )
	{
		length++;
		list = list->next;
	}
	return length;
}

void PointerToNthNode ( Node *list , int n , Node *ptr)
{
	

}	
