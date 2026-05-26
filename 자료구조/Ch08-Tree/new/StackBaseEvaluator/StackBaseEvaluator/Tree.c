#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* MakeNumNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data.value = data;
	node->data.isOp = 0;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

Node* MakeOperatorNode(char op)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data.op = op;
	node->data.isOp = 1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int Evaluate(Node* root)
{


	if (root->data.isOp == 0)
		return root->data.value;

	int left = Evaluate(root->left);
	int right = Evaluate(root->right);

	switch (root->data.op)
	{
	case'+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	}
	
	return 0;
}