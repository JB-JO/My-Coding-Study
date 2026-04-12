#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode* ndA = MakeBTreeNode(); //노드 A 생성

	BTreeNode* ndB = MakeBTreeNode(); // 노드 B 생성

	BTreeNode* ndC = MakeBTreeNode(); // 노드 C 생성

	BTreeNode* ndD = MakeBTreeNode();

	SetData(ndA, 1557);
	SetData(ndB, 121);
	SetData(ndC, 156);
	SetData(ndD, 123);

	MakeLeftSubTree(ndA, ndB); // 노드 A의 왼쪽 자식 노드로 노드 B연결

	MakeRightSubTree(ndA, ndC); // 노드 A의 오른쪽 자식 노드로 노드 C연결

	MakeLeftSubTree(ndB, ndD);

	printf("%d\n", GetData(GetLeftSubTree(ndA)));
	printf("%d\n", GetData(GetRightSubTree(ndA)));

	InorderTraverse(ndA);

	return 0;
}