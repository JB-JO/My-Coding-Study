#include "SimpleHeap.h"

void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //부모노드의 인덱스 값을 반환하는 헬퍼
{
	return idx / 2;
}

int GetLChildIDX(int idx) // 왼쪽 자식노드의 인덱스 값을 반환하는 헬퍼
{
	return idx * 2;
}

int GetRChileIDX(int idx)  // 오른쪽 자식노드의 인덱스 값을 반환하는 헬퍼
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) // 우선순위가 높은 자식의 인덱스 값 반환
{
	if (GetLChildIDX(idx) > ph->numOfData) // numOfData 는 마지막 노드의 고유번호이니 자식노드의 값이 이보다 크면 존재하지 않는 자식노드
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // 완전이진트리이므로 자식노드가 하나 존재한다면 왼쪽 자식노드이다.
		return GetLChildIDX(idx);
	else
	{
		//오른쪽 자식의 우선순위가 높다면,(숫자가 작을수록 우선순위가 높다고 했으니
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChileIDX(idx)].pr)
			return GetRChileIDX(idx); //오른쪽 자식 노드의 인덱스 값 반환
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;
	HeapElem nelem = { pr, data };

	while (idx != 1)
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data; // 반환을 위해 삭제할 데이터 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드를 저장

	int parentIdx = 1; // 루트 노드가 위치해야 할 인덱스 값 저장 단, 해당 변수는 마지막 노드가 저장될 위치정보를 담게됨.
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) // 루트노드의 우선순위가 높은 자식 노드를 시작으로 반복문을 시작
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위를 비교
			break; // 마지막 노드의 우선순위가 높다면 반복문을 탈출함

		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 올림.
		parentIdx = childIdx; // 마지막 노드가 저장될 위치정보를 한레벨 내림
	} // 반복문 탈출 시 parentIdx에는 마지막 노드의 위치정보를 저장하고 있음

	ph->heapArr[parentIdx] = lastElem; // 마지막 노드를 최종적으로 저장함.
	ph->numOfData -= 1;
	return retData;
}