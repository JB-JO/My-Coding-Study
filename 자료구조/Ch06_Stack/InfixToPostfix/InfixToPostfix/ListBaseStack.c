#include <stdio.h>
#include "ListBaseStack.h"
#include <malloc.h>

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
	Data temp = 0;
	Node* rep = NULL;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Empty!");

		exit(-1);
	}
	else
	{
		temp = pstack->head->data;
		rep = pstack->head;

		pstack->head = pstack->head->next;

		free(rep);

		return temp;
	}
}

Data SPeek(Stack* pstack)
{
	Data temp = 0;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Empty !");
		
		exit(-1);
	}
	else
	{
		temp = pstack->head->data;

		return temp;
	}
}