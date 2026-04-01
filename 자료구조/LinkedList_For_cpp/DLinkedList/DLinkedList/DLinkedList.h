#pragma once
#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

typedef int LData;

class DLinkedList
{
private:
	struct Node
	{
		LData data;
		Node* next;
	};


	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);

	void FInsert(LData data);
	void SInsert(LData data);

public:
	DLinkedList();

	~DLinkedList();

	void LInsert(LData data);

	bool LFirst(LData* pdata);
	bool LNext(LData* pdata);

	LData LRemove();
	int LCount() const;

	void SetSortRule(int(*comp)(LData d1, LData d2));
};

#endif // !__D_LINKED_LIST_H__

