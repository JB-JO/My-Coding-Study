#include <iostream>
#include "DLinkedList.h"
using namespace std;

DLinkedList::DLinkedList()
{
	this->head = new Node;

	this->head->next = nullptr;
	this->cur = nullptr;
	this->before = nullptr;
	this->comp = nullptr;
	this->numOfData = 0;
}

DLinkedList::~DLinkedList()
{
	Node* temp = head;
	Node* nextNode;

	while (temp != nullptr)
	{
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
}

void DLinkedList::FInsert(LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = head->next;
	head->next = newNode;

	numOfData++;
}

void DLinkedList::SInsert(LData data)
{
	Node* newNode = new Node;
	Node* pred = head;
	newNode->data = data;

	while (pred->next != nullptr && comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	numOfData++;
}

void DLinkedList::LInsert(LData data)
{
	if (comp == nullptr)
		FInsert(data);
	else
		SInsert(data);
}

bool DLinkedList::LFirst(LData* pdata)
{
	if (head->next == nullptr)
		return 0;
	
	before = head;
	cur = head->next;

	*pdata = cur->data;
	return 1;
}

bool DLinkedList::LNext(LData* pdata)
{
	if (cur->next == nullptr)
		return 0;

	before = cur;
	cur = cur->next;

	*pdata = cur->data;
	return 1;
}

LData DLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;
	cur = before;

	delete rpos;
	numOfData--;
	
	return rdata;
}

int DLinkedList::LCount()const
{
	return numOfData;
}

void DLinkedList::SetSortRule(int (*comp)(LData d1, LData d2))
{
	this->comp = comp;
}