#include <stdio.h>
#include <stdlib.h>

#define MAX   100

typedef struct btreeNode
{
	char data;
	struct btreeNode* left;
	struct btreeNode* right;
} BTreeNode;

typedef BTreeNode  Node;

Node* MakeNode(char data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* stack[MAX];
int top = -1;

void push(Node* bt)
{
	stack[++top] = bt;
}

Node* pop()
{
	return stack[top--];
}

void Inorder(Node* bt)
{
	if (bt == NULL)
		return bt->data;

	Inorder(bt->left);
	printf("%c", bt->data);
	Inorder(bt->right);
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
		else
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

	Inorder(root);

	return 0;
}