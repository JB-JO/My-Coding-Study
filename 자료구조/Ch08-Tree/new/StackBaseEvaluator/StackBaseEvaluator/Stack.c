#include "Stack.h"

static Node* stack[MAX];
static int top = -1;

void Push(Node* node)
{
	stack[++top] = node;
}

Node* Pop()
{
	return stack[top--];
}

Node* Peek()
{
	return stack[top];
}

int isEmpty()
{
	return top == -1;
}