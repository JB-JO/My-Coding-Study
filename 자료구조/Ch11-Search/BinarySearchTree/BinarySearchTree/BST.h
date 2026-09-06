#pragma once
#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree2.h"

typedef int BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);

BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif // !__BST_H__