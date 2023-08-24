#include<stdio.h>
#include "ll.h"
#include "llop.h"
int main (void)
{
	Node *list = NULL; 
	FormLinkedList(&list, 5);
	DisplayLinkedList(list);
	ReverseLinkedList(&list);
	DisplayLinkedList(list);	
	return 0;
}
