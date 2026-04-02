#include <iostream>
#include "DBLinkedList.h"
using namespace std;

int main(void)
{
	DBLinkedList list;
	Data data;

	list.ListInsert(1); list.ListInsert(2);
	list.ListInsert(3); list.ListInsert(4);
	list.ListInsert(5); list.ListInsert(6);
	list.ListInsert(7); list.ListInsert(8);

	if (list.LFirst(&data))
	{
		cout << data << " ";

		while (list.LNext(&data))
			cout << data << " ";

		while (list.LPrevious(&data))
			cout << data << " ";

		cout << '\n' << '\n';
	}


	return 0;
}