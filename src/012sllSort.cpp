/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int arr[3] = { 0, 0, 0 },i=0;
	struct node *cur = head;
	while (cur!=NULL){
		arr[cur->data]++;
		cur = cur->next;
	}
	cur = head;
	while (cur != NULL){
		cur->data = i;
		arr[i]--;
		if (arr[i] == 0)
			i++;
		cur = cur->next;
	}
}
void sll_012_sort1(struct node *head){
	struct node *start0 = NULL, *end0 = NULL, *start1 = NULL, *end1 = NULL, *start2 = NULL, *end2 = NULL, *cur;
	cur = head;
	while (cur != NULL){
		if (cur->data == 0){
			if (start0 == NULL)
				start0 = cur;
			else
				end0->next = cur;
			end0 = cur;
		}
		else if (cur->data == 1){
			if (start1 == NULL)
				start1 = cur;
			else
				end1->next = cur;
			end1 = cur;
		}
		else if (cur->data == 2){
			if (start2 == NULL)
				start2 = cur;
			else
				end2->next = cur;
			end2 = cur;
		}
		cur = cur->next;
	}
	if (start0 != NULL){
		head = start0;
		if (start1 != NULL){
			end0->next = start1;
			end1->next = start2;
		}
		else if (start2 != NULL)
			end0->next = start2;
		else
			end0->next = NULL;
	}
	else if (start1 != NULL){
		head = start1;
		if (start2 != NULL)
			end1->next = start2;
		else
			end1->next = NULL;
	}
	else
		head = start2;
}