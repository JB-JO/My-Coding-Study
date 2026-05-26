#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX   100

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

Node* stack[MAX];
int top = -1;

void push(Node* node)
{
	stack[++top] = node;
}

Node* pop()
{
	return stack[top--];
}

int Evaluate(Node* root)
{
	int left, right;

	if (root->data.isOp == 0)
		return root->data.value;

	left = Evaluate(root->left);
	right = Evaluate(root->right);

	switch (root->data.op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case'*':
		return left * right;
	case '/':
		return left / right;
	}
}

int main(void)
{
	char exp[] = "12 34 + 5 *";

	char* token = strtok(exp, " ");

	while (token != NULL)
	{
		if (isdigit(token[0]))
		{
			int num = atoi(token);
			Node* node = MakeNumNode(num);
			push(node);
		}
		else
		{
			Node* right = pop();
			Node* left = pop();

			Node* node = MakeOperatorNode(token[0]);
			node->left = left;
			node->right = right;

			push(node);
		}

		token = strtok(NULL, " ");
	}

	Node* root = pop();

	printf("Result: %d\n", Evaluate(root));

	return 0;
}