#include <iostream>
#include <string>
using namespace std;

typedef int Data;

class LL
{
private:
	struct Node
	{
		Data data;
		Node* next;
	};
	Node* tail = nullptr;
	Node* head = nullptr;
	int NumOfData = 0;

public:
	LL()
	{
		head = nullptr;
		tail = nullptr;
	}

	~LL()
	{
		Node* delNode;

		while (!LLIsEmpty())
		{
			delNode = head;
			head = head->next;

			delete delNode;
		}
	}

	bool LLIsEmpty()
	{
		if (head == nullptr)
			return 1;
		else
			return 0;
	}

	void LLFinset(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (LLIsEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		NumOfData++;
	}

	void LLLInsert(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (LLIsEmpty())
		{
			tail = newNode;
			head = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		NumOfData++;
	}

	Data LLRemove()
	{
		Node* delNode;
		Data tempData;

		if (LLIsEmpty())
			return -1;
		else
		{
			delNode = head;
			head = head->next;

			if (head == nullptr)
				tail = nullptr;

			tempData = delNode->data;

			delete delNode;
			NumOfData--;

			return tempData;
		}
	}

	int LLCount()
	{
		return NumOfData;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	LL list;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		list.LLLInsert(i);

	while (list.LLCount() > 1)
	{
		list.LLRemove();

		int temp = list.LLRemove();
		list.LLLInsert(temp);
	}


	cout << list.LLRemove() << '\n';

	return 0;
}