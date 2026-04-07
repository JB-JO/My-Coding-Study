#include <iostream>
#include "Deque.h"
using namespace std;

int main(void)
{
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
			dq.DQAddFirt(x);
			break;

		case 2:
			cin >> x;
			dq.DQAddLast(x);
			break;

		case 3:
			cout << dq.DQIsEmpty() << '\n';
			break;

		case 4:
			cout << dq.DQCount() << '\n';
			break;

		case 5:
			cout << dq.DQRemoveFirst() << '\n';
			break;

		case 6:
			cout << dq.DQRemoveLast() << '\n';
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