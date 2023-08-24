#ifndef _STACK_H_

#include<stdlib.h>

struct node{
	int		element;
	struct node 	*next;	

};

void pushElement(int element);
int popElement(void);
void display(void);

#endif
