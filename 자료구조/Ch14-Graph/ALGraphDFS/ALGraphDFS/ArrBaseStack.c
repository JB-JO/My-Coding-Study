#include <stdio.h>
#include "ArrBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;

	if (pstack->topIndex >= 100)
		return FALSE;
	else
	    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	Data temp = 0;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Empty !");

		exit(-1);
	}
	else
	{
		temp = pstack->topIndex;
		pstack->topIndex -= 1;
		
		return pstack->stackArr[temp];
	} /* 여기서 반환하고 삭제한 인덱스는 왜 초기화를 하지 않는가? */
}    /* 그건 배열에서 현재 저장하고 있는 가장 마지막 정보를 가리키는 인덱스는 top으로 우리가 설정했음 */
    /* 그로 인해서 top값을 현재 -1해주었다면 다시 SPush함수가 호출되면 어떻게 되는가를 생각해보자 +1되면서 자연스럽게 그전의 정보는 지워지고 다시 data로 전달된 값이 저장되면서 초기화가 되지 않는가 */

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Empty !");

		exit(-1);
	}
	else
		return pstack->stackArr[pstack->topIndex];
}