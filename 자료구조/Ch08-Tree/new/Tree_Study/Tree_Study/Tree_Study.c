#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct btreeNode
{
	char data;
	struct btreeNode* left;
	struct btreeNode* right;
} BTNode;

typedef BTNode  Node;

Node* MakeNode(char rdata)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = rdata;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* stack[MAX];
int top = -1;

void push(Node* bt) {
	stack[++top] = bt;
}

Node* pop()
{
	return stack[top--];
}

void inorder(Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%c", root->data);
	inorder(root->right);
}

int main(void)
{
	char exp[] = "ABC*+";

	for (int i = 0; exp[i] != '\0'; i++)
	{
		char token = exp[i];
		
		if (token >= 'A' && token <= 'Z')
		{
			Node* node = MakeNode(token);
			push(node);
		}
		else // 스택 top는 항상 오른쪽 피연산자.                             
		{
			Node* right = pop();
			Node* left = pop();
			Node* node = MakeNode(token);
			node->left = left;
			node->right = right;
			push(node);
		}
	}
	Node* root = pop();

	inorder(root);

	return 0;
}