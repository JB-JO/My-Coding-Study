#include <iostream>
#include "DBLinkedList.h"
using namespace std;

DBLinkedList::DBLinkedList()
{
	head = nullptr;
	numOfData = 0;
	cout << "** DBLinkedList() Start ***" << endl;
}

DBLinkedList::~DBLinkedList()
{
	Node* temp;
	int i = 0;

	while(head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
		i++;
	}
	cout << "** DBLinkedList() End *****" << endl;
}

void DBLinkedList::ListInsert(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head;
	if (head != nullptr)
		head->prev = newNode;

	newNode->prev = nullptr;
	head = newNode;

	numOfData++;
}

bool  DBLinkedList::LFirst(Data* pdata)
{
	if (head == nullptr)
		return 0;

	cur = head;
	*pdata = cur->data;

	return 1;
}

bool DBLinkedList::LNext(Data* pdata)
{
	if (cur->next == nullptr)
		return 0;

	cur = cur->next;
	*pdata = cur->data;

	return 1;
}

bool DBLinkedList::LPrevious(Data* pdata)
{
	if (cur->prev == nullptr)
		return 0;

	cur = cur->prev;
	*pdata = cur->data;

	return 1;
}

int DBLinkedList::LCount()
{
	return numOfData;
}