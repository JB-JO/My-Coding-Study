#pragma once
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE      1
#define FALSE     0

#define QUE_LEN   100
typedef int Data;

typedef struct _nod_cQueue
{
	int front; // 책의 그림에 나오는 F라 표현된 멤버 (출구)
	int rear; // 책의 그림에 나오는 R이라 표현된 멤버 (입구)
	Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data DPeek(Queue* pq);

#endif // !__C_QUEUE_H__

