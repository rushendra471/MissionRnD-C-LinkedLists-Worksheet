/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head==NULL)
		return NULL;
	struct node *cur,*nxt;
	cur = head;
	nxt = head->next;
	int tmp;
	while (nxt != NULL){
		while (nxt != cur){
			if (nxt->num < cur->num){
				tmp = cur->num;
				cur->num = nxt->num;
				nxt->num = tmp;
			}
			cur = cur->next;
		}
		cur = head;
		nxt = nxt->next;
	}
	return cur;
}