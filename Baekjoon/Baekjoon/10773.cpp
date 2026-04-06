#include <iostream>
#include <algorithm>
using namespace std;

typedef int Data;

class Stack
{
private:
	struct Node
	{
		Data data;
		Node* next;
	};
	Node* head = nullptr;
	int numOfData = 0;

public:
	Stack()
	{
		this->head = nullptr;
	}

	~Stack()
	{
		Node* delNode;

		while (!SIsEmpty())
		{
			delNode = head;
			head = head->next;
			
			delete delNode;
		}
	}

	bool SIsEmpty()
	{
		if (head == nullptr)
			return 1;
		else
			return 0;
	}

	void SPush(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->next = head;
		head = newNode;

		numOfData++;
	}

	Data SPop()
	{
		Node* delNode;
		Data tempData;

		if (SIsEmpty())
			return -1;
		else
		{
			delNode = head;
			head = head->next;
			tempData = delNode->data;

			delete delNode;
			numOfData--;

			return tempData;
		}
	}

	Data SPeek()
	{
		if (SIsEmpty())
			return -1;
		else
			return head->data;
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack s;
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;

		if (command == 0)
			s.SPop();
		else
		{
			s.SPush(command);
		}
	}

	long long value = 0;

	while (!s.SIsEmpty())
	{
		value += s.SPop();
	}

	cout << value << '\n';

	return 0;
}