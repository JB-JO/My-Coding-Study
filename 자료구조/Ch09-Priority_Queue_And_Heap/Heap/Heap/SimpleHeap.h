#pragma once
#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE         1
#define FALSE        0

#define HEAP_LEN   100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
	Priority pr; // 값이 작을수록 높은 우선순위
	HData data;	
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph); //우선순위가 가장 높은 데이터 삭제되도록 정의

#endif // !__SIMPLE_HEAP_H__

// 힙을 구현하기는 하지만 우선순위 큐를 구현하는 목적으로 하는 헤더파일임을 생각해야한다.

// 힙은 완전 이진 트리임
// 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둠
// 따라서 힘에 저장된 노드의 개수와 마지막 노드의 고유번호는 일치함
// 노드의 고유번호가 노드에 저장되는 배열의 인덱스 값이 된다.
// 우선순위를 나타내는 정수 값이 작을수록 높은 우선순위를 나타낸다고 가정한다.