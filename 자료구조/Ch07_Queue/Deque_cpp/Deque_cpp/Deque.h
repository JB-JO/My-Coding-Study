#pragma once
#ifndef __DEQUE_H__
#define __DEQUE_H__

typedef int Data;

class Deque
{
private:
	struct Node
	{
		Data data;
		Node* next;
		Node* prev;
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	int numOfData = 0;

public:
	Deque();

	~Deque();

	bool DQIsEmpty();

	void DQAddFirt(Data data);

	void DQAddLast(Data data);

	Data DQRemoveFirst();

	Data DQRemoveLast();

	Data DQGetFirst();

	Data DQGetLast();

	int DQCount() const;
};

#endif // !__DEQUE_H__

