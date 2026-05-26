#pragma once
#ifndef __TREE_H__
#define __TREE_H__

typedef struct {
	int value;
	char op;
	int isOp;
} Data;

typedef struct btreeNode
{
	Data data;
	struct btreeNode* left;
	struct btreeNode* right;
} BTNode;

typedef BTNode Node;

Node* MakeNumNode(int data);
Node* MakeOperatorNode(char op);
int Evaluate(Node* root);

#endif // !__TREE_H__
