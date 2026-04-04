#include <iostream>
#include "ListBaseQueue.h"
using namespace std;

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;

	cout << "****** Queue() *******" << endl;
}

Queue::~Queue()
{
	Node* delNode;
	while (!QIsEmpty())
	{
		delNode = front;
		front = front->next;

		delete delNode;
	}
	cout << "***** ~Queue() *******" << endl;
}

bool Queue::QIsEmpty() const
{
	if (this->front == nullptr) // front가 nullptr이라는 것은 현재 비어있다라는 소리.
		return 1;
	else
		return 0;
}

void Queue::Enqueue(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (QIsEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode; // 현재 마지막 노드의 next가 newNode를 가리키게 한다.
		rear = newNode; // 이후 rear를 newNode를 가리키게 옮겨준다.
	}
}

Data Queue::Dequeue()
{
	Node* delNode;
	Data tempData;

	if (QIsEmpty())
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	else
	{
		delNode = front;
		tempData = delNode->data;
		front = front->next;

		delete delNode;

		return tempData;
	}
}

Data Queue::QPeek()
{
	if (QIsEmpty())
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	else
	{
		return front->data;
	}
}