#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack
{
private:
	vector<int>  S;

public:
	bool IsEmpty()
	{
		if (S.size() == 0)
			return 1;
		else
			return 0;
	}

	void Push(int a)
	{
		S.push_back(a);
	}

	int Pop()
	{
		if (IsEmpty())
			return -1;

		int idx = S.size() - 1;

		int x = S[idx];

		S.pop_back();

		return x;
	}

	int Peek()
	{
		if (IsEmpty())
			return -1;

		int idx = S.size() - 1;
		int x = S[idx];

		return x;
	}

	int Size()
	{
		return S.size();
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack stack;

	int N;
	cin >> N;

	while (N--)
	{
		int i;
		string str;
		cin >> str;

		if (str == "push")
		{
			cin >> i;
			stack.Push(i);
		}
		else if (str == "pop")
			cout << stack.Pop() << '\n';
		else if (str == "size")
			cout << stack.Size() << '\n';
		else if (str == "empty")
			cout << stack.IsEmpty() << '\n';
		else if (str == "top")
			cout << stack.Peek() << '\n';
	}


	return 0;
}