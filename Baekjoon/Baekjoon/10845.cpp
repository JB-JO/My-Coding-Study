#include <iostream>
#include <string>
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
	int NumOfData = 0;

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
		newNode->data = data;
		newNode->next = nullptr;

		if (QIsEmpty())
		{
			front = newNode;
			rear = newNode;

			NumOfData++;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;

			NumOfData++;
		}
		
	}

	Data QPop()
	{
		Node* delNode;
		Data tempData;

		if (QIsEmpty())
			return -1;
		else
		{
			delNode = front;
			front = front->next;

			tempData = delNode->data;

			delete delNode;
			NumOfData--;

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

	Data Qrear()
	{
		if (QIsEmpty())
			return -1;
		else
			return rear->data;
	}

	int QCount()
	{
		return NumOfData;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Queue queue;

	int N;
	cin >> N;

	while (N--)
	{
		string command;
		cin >> command;

		int X = 0;

		if (command == "push")
		{
			cin >> X;
			queue.QPush(X);
		}
		else if (command == "pop")
			cout << queue.QPop() << '\n';
		else if (command == "size")
			cout << queue.QCount() << '\n';
		else if (command == "empty")
			cout << queue.QIsEmpty() << '\n';
		else if (command == "front")
			cout << queue.Qfront() << '\n';
		else if (command == "back")
			cout << queue.Qrear() << '\n';
	}

	return 0;
}