#include <stdio.h>
#include <malloc.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;
	
	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Node* delNode;
	Data tempData;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	tempData = pstack->head->data;
	delNode = pstack->head;
	pstack->head = pstack->head->next;

	free(delNode);
	return tempData;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	else
		return pstack->head->data;
}