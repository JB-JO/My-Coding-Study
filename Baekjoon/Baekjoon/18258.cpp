#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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

	int queueSize = 0;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	~Queue()
	{
		Node* delNode;

		while (!QIsEmpty())
		{
			delNode = front;
			front = front->next;

			delete delNode;
		}
	}

	bool QIsEmpty()
	{
		if (front == nullptr)
			return 1;
		else
			return 0;
	}

	void QPush(Data data)
	{
		Node* newNode = new Node;
		newNode->next = nullptr;
		newNode->data = data;

		if (QIsEmpty())
		{
			front = newNode;
			rear = newNode;

			queueSize++;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;

			queueSize++;
		}
	}

	Data QPop()
	{
		Node* delNode;
		Data tempData;

		if (QIsEmpty())
			return -1;
		if (front == nullptr) {
			rear = nullptr;
		}
		else
		{
			delNode = front;
			front = front->next;
			tempData = delNode->data;

			delete delNode;
			queueSize--;

			return tempData;
		}
	}

	Data Qfront()
	{
		if (QIsEmpty())
			return -1;
		else
			return front->data;
	}

	Data Qback()
	{
		if (QIsEmpty())
			return -1;
		else
			return rear->data;
	}

	Data QSize()
	{
		return queueSize;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Queue q;
	int N;
	cin >> N;

	while (N--)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int X;
			cin >> X;

			q.QPush(X);
		}
		else if (command == "pop")
		{
			int i = q.QPop();
			cout << i << '\n';
		}
		else if (command == "size")
			cout << q.QSize() << '\n';
		else if (command == "empty")
			cout << q.QIsEmpty() << '\n';
		else if (command == "front")
			cout << q.Qfront() << '\n';
		else if (command == "back")
			cout << q.Qback() << '\n';
	}
	

	return 0;
}