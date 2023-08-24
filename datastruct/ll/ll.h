#ifndef _LL_H
#define _LL_H

#include <stddef.h>

struct node{
	int element;
	struct node *next;
};

typedef struct node Node;

//This will form the linked list with n number of nodes

void FormLinkedList(Node **list,int n);

//This will form the linked list from the pointer array with n elements
void FormLinkedListArray(Node *list, int *ptr, int n);


//This will Display Linked list
void DisplayLinkedList(Node *list);

//This will find the length of linked list

int LengthOfLinkedList( Node *list);


#endif
