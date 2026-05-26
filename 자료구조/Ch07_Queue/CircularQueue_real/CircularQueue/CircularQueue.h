#pragma once
#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#define QUE_LEN     100

#define TRUE        1
#define FLASE       0

typedef int Data;

typedef struct _c_qeueue {
	Data queArr[QUE_LEN];
	int front, rear;
} Queue;

int QIsEmpty(Queue* const pq);
void QueueInit(Queue* const pq);

int NextPosIdx(int pos);

void enQueue(Queue* const pq, Data data);
Data deQueue(Queue* const pq);
Data QPeek(Queue* const pq);

void PrintQueue(Queue* const pq);

#endif // !__CIRCULAR_QUEUE_H__


