#pragma once
#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE     1
#define FALSE    0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	Node* tail; //꼬리를 나타내는
	Node* cur; //참조를 위한 변수
	Node* before; //삭제를 위해
	int numOfData;
} CList;

typedef CList List;

void ListInit(List* plist); //리스트의 생성
void LInsert(List* plist, Data data); //꼬리에 노드를 추가
void LInsertFront(List* plist, Data data); // 머리에 노드를 추가

int LFirst(List* plist, Data* data);
int LNext(List* plist, Data* data); // 연결리스트를 계속 순회하는 형태로 변경
Data LRemove(List* plist); // 이전과 기능동일
int LCount(List* plist);

#endif // !__C_LINKED_LIST_H__
