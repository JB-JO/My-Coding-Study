#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void); // 노드의 생성.
BTData GetData(BTreeNode* bt); // 노드에 저장된 데이터 반환
void SetData(BTreeNode* bt, BTData data); // 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt); // 왼쪽 서브 트리의 주소 값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt); // 오른쪽 서브 트리의 주소 값 반환.

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // main의 서브 왼쪽 트리로 sub를 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // main의 오른쪽 서브 트리로 sub를 연결.

void InorderTraverse(BTreeNode* bt);
void PreorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);

#endif // !__BINARY_TREE_H__
