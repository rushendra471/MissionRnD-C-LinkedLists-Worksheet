/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	if (N<0)
		N *= -1;
	struct node *temp,*start=NULL;
	if (N == 0){
		start = (struct node *)malloc(sizeof(struct node));
		start->num = 0;
		start->next = NULL;
	}
	while (N>0){
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = N % 10;
		temp->next = start;
		start=temp;
		N /= 10;
	}
	return start;
}