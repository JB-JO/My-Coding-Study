#include <stdio.h>
#include <stdlib.h>
#define  MAX   100

typedef int Data;

typedef struct btreeNode
{
	Data data;
	struct btreeNode* left;
	struct btreeNode* right;
} BTNode;

typedef BTNode Node;

Node* MakeNode(Data data)
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
		return;

	Inorder(bt->left);
	printf("%c", bt->data);
	Inorder(bt->right);
}

int Evaluate(Node* bt)
{
	int left, right;
	
	if (bt->left == NULL && bt->right == NULL)
		return bt->data;
	
	left = Evaluate(bt->left);
	right = Evaluate(bt->right);

	switch (bt->data)
	{
	case '+' :
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

int main(void)
{
	char exp[] = "412*+";

	for (int i = 0; exp[i] != '\0'; i++)
	{
		char token = exp[i];
		if (token >= '0' && token <= '9')
		{
			Node* node = MakeNode(token - '0');
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

	printf("결과: %d\n", Evaluate(root));

	return 0;
}
