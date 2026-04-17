#include <stdio.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "ExpressionTree.h"

BTreeNode* MakeExpTree(char exp[]) // 수식트리의 루트노드의 주소값을 반환함.
{
	Stack stack;
	BTreeNode* pnode;
	int expLen = strlen(exp);
	int i;
	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();
		if (isdigit(exp[i])) // 만약 피연산자라면 스택으로 옮긴다.
		{
			SetData(pnode, exp[i] - '0'); // 문자를 정수로 바꿔서 저장한다.
		}
		else // 연산자라면.
		{
			MakeRightSubTree(pnode, SPop(&stack)); // 스택에서 두 개의 피연산자를 꺼내어 자식 노드로 연결.
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode); // 자식 노드를 연결해서 만들어진 트리는 다시 스택으로 옮긴다.
	}
	return SPop(&stack);
}

int EvalueateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvalueateExpTree(GetLeftSubTree(bt));
	op2 = EvalueateExpTree(GetRightSubTree(bt));
	
	switch(GetData(bt))
	{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}
	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}