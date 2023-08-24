
#include "ll.h"
#include "llop.h"
void ReverseLinkedList(Node **list)
{
	Node *head = *list;
	Node *pre, *cur, *temp;
	pre = head;
	cur = head->next;
	pre->next = NULL;	
	while(cur)
	{
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
			
	}
	*list = pre;
	
}
