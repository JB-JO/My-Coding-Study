#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) // 새 노드를 꼬리에 추가하는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode; //tail이 newNode를 가리키게 된다.
		newNode->next = newNode; // 원형이니 계속해서 순환해야하므로 첫 노드일 경우 머리이자 꼬리이므로 자신의 next가 자기 자신을 가리키게 구현한다.
	}
	else
	{
		newNode->next = plist->tail->next; // 테일의 넥스트가 가지고 있는 주소를 새 노드가 가리키게 넘겨준다.
		plist->tail->next = newNode; // 테일의 넥스트가 새 노드를 가리키게 만들어서 꼬리에 추가한다.
		plist->tail = newNode; // 테일이 가리키고 있어야 꼬리이므로 테일이 가리키는 구조를 만들어준다. !유일한 차이점!
	}

	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data) // 새 노드를 머리에 추가하는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	if (plist->tail == NULL)
		return FALSE;

	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail)
	{
		if (plist->tail->next == NULL)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}