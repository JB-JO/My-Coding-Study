#pragma once
#ifndef __BINARY_TREE_2_H__
#define __BINARY_TREE_2_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VistFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VistFuncPtr action);
void InorderTraverse(BTreeNode* bt, VistFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VistFuncPtr action);

#endif // !__BINARY_TREE_2_H__

