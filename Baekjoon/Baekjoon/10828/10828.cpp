#include <iostream>
#include <string>
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
		head = nullptr;
	}

	~Stack()
	{
		Node* delNode;

		while (!SIsEmpty())
		{
			delNode = this->head;
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

		newNode->next = this->head;
		this->head = newNode;

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
			delNode = this->head;
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

	int SCount()
	{
		return numOfData;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack stack;

	int N;
	cin >> N;

	while (N--)
	{
		string command;
		cin >> command;
		
		if (command == "push")
		{
			int x;
			cin >> x;

			stack.SPush(x);
		}
		else if (command == "top")
			cout << stack.SPeek() << '\n';
		else if (command == "pop")
			cout << stack.SPop() << '\n';
		else if (command == "size")
			cout << stack.SCount() << '\n';
		else if (command == "empty")
			cout << stack.SIsEmpty() << '\n';
	}

	return 0;
}