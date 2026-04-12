#include <stdio.h>
#include <malloc.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;

	return nd;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) // 기존 연결이 있다면 삭제 후 새로 받은 주소를 연결.
{
	if (main->left != NULL)
		free(main->left); // 만약 삭제할 노드가 이진트리로 자식노드가 있는 구조라면 이렇게 할 경우 메모리 누수가 일어난다.

	main->left = sub; // 위의 문제는 순회로 해결한다.
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void InorderTraverse(BTreeNode* bt) // 중위 순회
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d\n", bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt) // 전위 순회
{
	if (bt == NULL)
		return;

	printf("%d\n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt) // 후위 순회
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d\n", bt->data);
}