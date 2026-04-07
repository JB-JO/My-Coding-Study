#include <iostream>
#include "Deque.h"

Deque::Deque()
{
	head = nullptr;
	tail = nullptr;
}

Deque::~Deque()
{
	Node* delNode = head;

	while (!DQIsEmpty())
	{
		head = head->next;
		delete delNode;
	}
}

bool Deque::DQIsEmpty()
{
	if (head == nullptr)
		return 1;
	else
		return 0;
}

void Deque::DQAddFirt(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())
		tail = newNode;
	else
		head->prev = newNode;

	newNode->prev = nullptr;
	head = newNode;

	numOfData++;
}

void Deque::DQAddLast(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (DQIsEmpty())
		head = newNode;
	else
		tail->next = newNode;

	newNode->next = nullptr;
	tail = newNode;

	numOfData++;
}

Data Deque::DQRemoveFirst()
{
	Node* delNode = head;
	Data tempData;

	if (DQIsEmpty())
		return -1;

	tempData = delNode->data;

	head = head->next;

	delete delNode;

	if (head == nullptr)
		tail = nullptr;
	else
		head->prev = nullptr;

	numOfData--;

	return tempData;
}

Data Deque::DQRemoveLast()
{
	Node* delNode = tail;
	Data tempData;

	if (DQIsEmpty())
		return -1;

	tempData = tail->data;
	tail = tail->prev;

	if (tail == nullptr)
		head = nullptr;
	else
		tail->next = nullptr;

	numOfData--;

	return tempData;
}

Data Deque::DQGetFirst()
{
	if (DQIsEmpty())
		return -1;
	else
		return head->data;
}

Data Deque::DQGetLast()
{
	if (DQIsEmpty())
		return -1;
	else
		return tail->data;
}

int Deque::DQCount() const
{
	return numOfData;
}