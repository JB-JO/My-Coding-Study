#pragma once
#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE       1
#define FALSE      0
#define STACK_LEN  100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack); /* 스택의 초기화. 스택 생성시 가장 먼저 호출되어야 하는 함수 */
int SIsEmpty(Stack* pstack);/* 스택이 빈 경우 TRUE(1)을 아닌 경우 FALSE(0)을 반환해야 한다. */

void SPush(Stack* pstack, Data data); /* 스택에 데이터를 저장. 매개변수 data로 전달된 값을 저장한다. */
Data SPop(Stack* pstack);/* 마지막에 저장된 요소 삭제. 삭제된 데이터 반환. 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 함 (즉, SIsEmpty인지 확인을 한 후 0을 받으면 실행되어야함) */
Data SPeek(Stack* pstack); /* 마지막에 저장된 요소를 반환만 함 (삭제는 하지않는다.) 이 함수 또한 데이터가 하나 이상 존재함이 보장되어야 한다. */

#endif // !__AB_STACK_H__

