#pragma once
#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

typedef int Data;

class ListStack
{
private: // 여기는 접근 불가
	struct Node
	{
		Data data;
		Node* next;
	};
	Node* head;

public:
	ListStack(); // 생성자 함수 본래 c스타일에서 StackInit을 담당한다.

	~ListStack();

    bool SIsEmpty(); // 비었는지 아닌지만 리턴하면 되니까 bool 자료형 사용

	void SPush(Data data); // head->next가 nullptr인지 아닌지는 알 필요가 없다. 어짜피 우리는 머리에 추가하는 형식이라 head->next는 계속 변경될거다.
	Data SPop(); //일단 비었는지 검사하고 이 함수는 마지막 노드의 데이터를 반환하고 삭제도 해야함
	Data SPeek(); // 얘도 비었는지 확인하고 데이터 반환은 하는데 삭제는 안해도됨.
};

#endif // !__LIST_STACK_H__
