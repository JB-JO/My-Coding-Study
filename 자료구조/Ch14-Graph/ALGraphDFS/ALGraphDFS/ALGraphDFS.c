#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	// 정점의 수에 해당하는 길이의 리스트 배열을 생성
	pg->adjList = (List*)malloc(sizeof(List) * nv); // 간선 정보를 저장할 리스트 생성

	pg->numV = nv; // 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0; // 초기의 간선 수는 0개

	// 정점의 수만큼 생성된 리스트들을 초기화.
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);

	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c connected to: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)  // 처음 방문일 때 참인 if문
	{
		pg->visitInfo[visitV] = 1; // 방문한 것으로 기록
		printf("%c ", visitV + 65); // 방문한 정점의 이름을 출력해준다.
		return TRUE; // 방문 성공
	}
	return FALSE; // 방문 실패
}

void DFShowGraphVertex(ALGraph* pg, int startV)
{
	// 초기화 영역
	Stack stack;
	int visitV = startV;
	int nextV;
	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;
		if (VisitVertex(pg,nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}