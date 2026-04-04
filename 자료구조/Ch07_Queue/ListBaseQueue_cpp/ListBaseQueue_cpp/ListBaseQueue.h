#pragma once
#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

typedef int Data;

class Queue
{
private:
	struct Node
	{
		Data data;
		Node* next;
	};

	Node* front = nullptr;
	Node* rear = nullptr;

public:
	Queue();

	~Queue();
	
	bool QIsEmpty() const;

	void Enqueue(Data data);
	Data Dequeue();
	Data QPeek();
};

#endif // !__LB_QUEUE_H__

