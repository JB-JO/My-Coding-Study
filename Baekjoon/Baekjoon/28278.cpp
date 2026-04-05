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
		if (this->head == nullptr)
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
		{
			cout << "-1" << '\n';
			return -1;
		}
		else
		{
			delNode = head;
			head = head->next;
			tempData = delNode->data;

			delete delNode;
			numOfData--;
			cout << tempData << '\n';
			return tempData;
		}
	}

	Data SPeek()
	{
		if (SIsEmpty())
		{
			cout << "-1" << '\n';
			return -1;
		}
		else {
			cout << head->data << '\n';
			return head->data;
		}
	}

	void SCount()
	{
		cout << numOfData << '\n';
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack s;
	int N;
	cin >> N;

	while (N--)
	{
		int command;
		cin >> command;

		switch (command)
		{
		case 1:
		{
			int X;
			cin >> X;
			s.SPush(X);
			break;
		}
		case 2:
		{
			s.SPop();
			break;
		}
		case 3:
		{
			s.SCount();
			break;
		}
		case 4:
		{
			cout << s.SIsEmpty() << '\n';
			break;
		}
		case 5:
		{
			s.SPeek();
			break;
		}
		}
	}


	return 0;
}