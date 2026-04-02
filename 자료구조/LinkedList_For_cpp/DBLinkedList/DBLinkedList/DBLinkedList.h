#pragma once
#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

typedef int Data;

class DBLinkedList
{
private:
	struct Node
	{
		Data data;
		Node* next;
		Node* prev;
	};

	Node* head = nullptr;
	Node* cur = nullptr;
	int numOfData = 0;

public:
	DBLinkedList();

	~DBLinkedList();

	void ListInsert(Data data);

	bool LFirst(Data* pdata);
	bool LNext(Data* pdata);
	bool LPrevious(Data* pdata);

	int LCount();
};

#endif // !__DB_LINKED_LIST_H__

