#pragma once
#ifndef  __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "DLinkedList.h"

// 정점의 이름들을 상수화 
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

//그래프의 모든 정점 정보를 출력하는 함수
// DFS 즉, 깊이 우선 탐색을 기반으로 정의할 함수
void DFShowGraphVertex(ALGraph* pg, int startV);

#endif // ! __AL_GRAPH_H__
