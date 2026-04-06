#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	Node* delNode = pdeq->head;
	Data tempData;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	tempData = pdeq->head->data;

	pdeq->head = pdeq->head->next;
	free(delNode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return tempData;
}

Data DQRemoveLast(Deque* pdeq)
{
	Node* delNode = pdeq->tail;
	Data tempData;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	tempData = pdeq->tail->data;

	pdeq->tail = pdeq->tail->prev;
	free(delNode);

	if (pdeq->tail== NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return tempData;
}
	

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	else
		return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	else
		return pdeq->tail->data;
}