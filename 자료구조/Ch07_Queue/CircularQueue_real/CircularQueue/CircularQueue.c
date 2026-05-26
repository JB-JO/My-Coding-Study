#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

int QIsEmpty(Queue* const pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void QueueInit(Queue* const pq)
{
	pq->front = 0;
	pq->rear = 0;
}

void enQueue(Queue* const pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Queue Memory Error");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data deQueue(Queue* const pq)
{
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue* const pq)
{
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error");
		exit(-1);
	}
	return pq->queArr[pq->front];
}

void PrintQueue(Queue* const pq)
{
	int i;

	printf("\n\n\t\tQueue Display(FIFO): ");

	if (QIsEmpty(pq))
		printf("\n\n\t\tQueue is Empty\n");
	else {
		for (i = pq->front; i <= QUE_LEN - 1; i++)
			printf("%d ", pq->queArr[i]);
	}
	puts("");
}