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

	int n;
	cin >> n;

	Stack S;

	string result = "";
	int count = 1;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while (count <= x)
		{
			S.SPush(count);
			result += "+\n";
			count++;
		}

		if (S.SPeek() == x)
		{
			S.SPop();
			result += "-\n";
		}
		else
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << result;

	return 0;
}