#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

//main.c는 챕터3에 있는 ListMain.c를 살짝만 고치자

void ListInit(List* plist) 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));  //새 노드 생성
	newNode->data = data;                        //새 노드에 데이터 저장(유효한 데이터 저장)

	newNode->next = plist->head->next;            //새 노드가 다른 노드를 가리키게 함
	plist->head->next = newNode;                 // 더미 노드가 새 노드를 가리키게 함

	(plist->numOfData)++;                        // 저장된 노드의 수를 하나 증가시킴
}

void SInsert(List* plist, LData data)
{

}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;                
	plist->before = plist->head;     //before는 더미 노드를 가리키게 함
	plist->cur = plist->head->next;  // cur은 첫 번째 노드를 가리키게 한다.

	*pdata = plist->cur->data;      // 첫 번째 노드의 데이터를 전달
	return TRUE;                    // 데이터 반환 성공
}

int LNext(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)  //before를 옮긴다는 븅신같은 짓거리는 하지말자!
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{

}

void SetSortRule(List* plist, int (*comp)(LData D1, LData d2)) 
{

}
