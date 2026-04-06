#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef char Data;

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

	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		string PS; // 문제에서 문자열로 입력한다고 했으니 string으로 입력받는다.
		cin >> PS;

		Stack s; // 루프문 밖에서 선언시 s를 초기화하는 코드가 별도로 필요하다.

		bool isPossble = true; // 짝이 맞는지를 확인하는 변수.

		for (int j = 0; j < PS.length(); j++)
		{
			if (PS[j] == '(') //처음이든 아니든 일단 ( 를 입력받으면 넣어줌.
				s.SPush(PS[j]);
			else
			{
				if (s.SIsEmpty()) // 정상적인 상황에서 짝이 맞다면 ( 문자가 무조건 들어있는 상황이어야 한다. 즉 여는 괄호 없이 닫는 괄호만들어오는 상황
				{
					isPossble = false;
					break;
				}
				else // 짝이 맞다면 넣을 필요도 없이 ( 하나를 짝지어서 내보낸다.
					s.SPop();
			}
		}

		if (isPossble == true && s.SIsEmpty()) // 루프문을 정상적으로 다 돌리고 나온 경우 스택은 비게 되며 isPossble 변수 또한 문제 없이 true인 상황일 것이다.
			cout << "YES" << '\n';
		else // 조건 두개 중 하나라도 맞지 않는다는 것은 루프문 중간에 튕겨져 나왔다는 소리.
			cout << "NO" << '\n';
	}

	return 0;
}