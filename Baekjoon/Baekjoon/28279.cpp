#include <iostream>
using namespace std;

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
	Deque()
	{
		head = nullptr;
		tail = nullptr;
	}

	~Deque()
	{
		Node* delNode;

		while (!DQIsEmpty())
		{
			delNode = head;
			head = head->next;
			delete delNode;
		}
	}

	bool DQIsEmpty()
	{
		if (head == nullptr)
			return 1;
		else
			return 0;
	}

	void DQAddFirst(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->next = head;

		if (DQIsEmpty())
			tail = newNode;
		else
			head->prev = newNode;

		newNode->prev = nullptr;
		head = newNode;

		numOfData++;
	}

	void DQAddLast(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->prev = tail;

		if (DQIsEmpty())
			head = newNode;
		else
			tail->next = newNode;

		newNode->next = nullptr;
		tail = newNode;

		numOfData++;
	}

	Data DQRemoveFirst()
	{
		Node* delNode = head;
		Data tempData;

		if (DQIsEmpty())
			return -1;
		else
		{
			head = head->next;
			tempData = delNode->data;

			delete delNode;
		}

		if (head == nullptr)
			tail = nullptr;
		else
			head->prev = nullptr;
		
		numOfData--;

		return tempData;
	}

	Data DQRemoveLast()
	{
		Node* delNode = tail;
		Data tempData;

		if (DQIsEmpty())
			return -1;

		tail = tail->prev;
		tempData = delNode->data;

		delete delNode;

		if (tail == nullptr)
			head = nullptr;
		else
			tail->next = nullptr;

		numOfData--;

		return tempData;
	}

	Data DQGetFirst()
	{
		if (DQIsEmpty())
			return -1;
		else
			return head->data;
	}

	Data DQGetLast()
	{
		if (DQIsEmpty())
			return -1;
		else
			return tail->data;
	}

	int DQCount()
	{
		return numOfData;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Deque dq;
	int N;
	cin >> N;

	int x;

	while (N--)
	{
		int command;
		cin >> command;

		switch (command)
		{
		case 1:
			cin >> x;
			dq.DQAddFirst(x);
			break;
		case 2:
			cin >> x;
			dq.DQAddLast(x);
			break;
		case 3:
			cout << dq.DQRemoveFirst() << '\n';
			break;
		case 4:
			cout << dq.DQRemoveLast() << '\n';
			break;
		case 5:
			cout << dq.DQCount() << '\n';
			break;
		case 6:
			cout << dq.DQIsEmpty() << '\n';
			break;
		case 7:
			cout << dq.DQGetFirst() << '\n';
			break;
		case 8:
			cout << dq.DQGetLast() << '\n';
			break;
		default:
			break;
		}

	}
	
	return 0;
}