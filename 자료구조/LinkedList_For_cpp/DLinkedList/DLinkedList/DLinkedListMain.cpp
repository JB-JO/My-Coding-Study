#include <iostream>
#include "DLinkedList.h"
using namespace std;

int main(void)
{
	DLinkedList list;
	int data;

	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	cout << "현재 데이터의 수: " << list.LCount() << '\n';

	if (list.LFirst(&data))
	{
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";
	}
	cout << '\n' << '\n';

	if (list.LFirst(&data))
	{
		if (data == 22)
			list.LRemove();

		while (list.LNext(&data))
		{
			if (data == 22)
				list.LRemove();
		}
	}

	cout << "현재 데이터의 수: " << list.LCount() << '\n';

	if (list.LFirst(&data))
	{
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";
	}
	cout << '\n';

	return 0;
}
