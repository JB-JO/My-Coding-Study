#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef char Data;

class LinkedList
{
private:
	struct Node
	{
		Data data;
		Node* next;
		Node* prev;
	};
	Node* head = nullptr;
	Node* cur = nullptr; // 커서.
	Node* tail = nullptr;
	int numOfData = 0;

public:
	LinkedList()
	{
		head = new Node;
		tail = new Node;

		head->prev = nullptr;
		head->next = tail;

		tail->next = nullptr;
		tail->prev = head;

		cur = head;
	}
	
	~LinkedList()
	{
		Node* delNode;

		while (!LIsEmpty())
		{
			delNode = tail->prev;

			tail->prev->prev->next = tail;
			tail->prev = tail->prev->prev;

			delete delNode;
		}
		delete head;
		delete tail;
	}

	bool LIsEmpty()
	{
		if (head->next == tail)
			return 1;
		else
			return 0;
	}

	void LInsert(Data data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		newNode->prev = cur;
		newNode->next = cur->next;

		cur->next->prev = newNode;
		cur->next = newNode;

		cur = newNode;

		numOfData++;
	}

	int LFirst()
	{
		if (head->next == tail)
			return 0;
		
		cur = head->next;
	}

	void LNext()
	{
		if (cur->next != tail)
			cur = cur->next;
	}

	void LPrevious()
	{
		if(cur != head)
			cur = cur->prev;
	}

	void LRemove()
	{
		if (cur == head) return;

		Node* delNode = cur;

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;

		cur = cur->prev;

		delete delNode;
		
		numOfData--;
	}

	void PrintAll()
	{
		Node* temp = head->next;

		while (temp != tail)
		{
			cout << temp->data;
			temp = temp->next;
		}
		cout << '\n';
	}

	int LCount()
	{
		return numOfData;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	LinkedList Llist;
	for (int i = 0; i < S.length(); i++)
		Llist.LInsert(S[i]);

	int M;
	cin >> M;

	for (int a = 0; a < M; a++)
	{
		string command;
		cin >> command;

		if (command == "L")
			Llist.LPrevious();
		else if (command == "D")
			Llist.LNext();
		else if (command == "B")
			Llist.LRemove();
		else if (command == "P")
		{
			char ap;
			cin >> ap;
			Llist.LInsert(ap);
		}
	}

	Llist.PrintAll();

	return 0;
}
