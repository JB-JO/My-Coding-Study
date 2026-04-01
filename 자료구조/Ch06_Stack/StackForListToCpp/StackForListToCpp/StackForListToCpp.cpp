#include <iostream>
#include "ListStack.h"
using namespace std;

ListStack::ListStack()
{
	this->head = nullptr;
}

ListStack::~ListStack()
{
	Node* temp = this->head;
	Node* nextNode;

	while (temp != nullptr)
	{
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}

}

bool ListStack::SIsEmpty()
{
	if (this->head == nullptr)
		return 1;
	else
		return 0;
}

void ListStack::SPush(Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = this->head;
	this->head = newNode;
}

Data ListStack::SPop()
{
	Data rdata;
	Node* temp;

	if (ListStack::SIsEmpty())
	{
		cout << "Stack Memory Error" << '\n';
		exit(-1);
	}

	rdata = this->head->data;
	temp = this->head;
	this->head = this->head->next;

	delete temp;

	return rdata;
}

Data ListStack::SPeek()
{
	if (ListStack::SIsEmpty())
	{
		cout << "Stack Memory Error" << '\n';
		exit(-1);
	}

	return this->head->data;
}