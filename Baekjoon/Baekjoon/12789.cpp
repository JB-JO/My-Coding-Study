#include <iostream>
#include <vector>
using namespace std;

class stack
{
private:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* head = nullptr;
	int numOfStack = 0;

public:
	stack()
	{
		head = nullptr;
	}

	~stack()
	{
		Node* delNode;
		while (!SIsEmpty())
		{
			delNode = head;
			head = head->next;
			delete delNode;
		}
	}

	void Push(int data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;

		numOfStack++;
	}

	bool SIsEmpty()
	{
		if (head == nullptr)
			return 1;
		else
			return 0;
	}

	int Pop()
	{
		Node* delNode;
		int tempData;

		if (SIsEmpty())
			return -1;
		else
		{
			delNode = head;
			tempData = head->data;
			head = head->next;

			delete delNode;
			numOfStack--;

			return tempData;
		}
	}

	int Peek()
	{
		if (SIsEmpty())
			return -1;
		else
		{
			return head->data;
		}
	}

	int SCount()
	{
		return numOfStack;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack S;

	int N, A;
	cin >> N;

	int now = 1;

	for (int i = 0; i < N; i++)
	{
		cin >> A;

		if (A == now)
			now++;
		else
			S.Push(A);

		while (!S.SIsEmpty() && S.Peek() == now) {
			S.Pop();
			now++;
		}
	}

	if (now == N + 1)
		cout << "Nice" << '\n';
	else
		cout << "Sad" << '\n';



	return 0;
}