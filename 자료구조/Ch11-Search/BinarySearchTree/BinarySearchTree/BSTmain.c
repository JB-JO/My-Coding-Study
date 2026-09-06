#include "BinaryTree2.h"
#include "BST.h"
#include <stdio.h>

int main(void)
{
	BTreeNode* bstRoot;  //BST의 루트노드를 가리키고 있음.
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 3);

	sNode = BSTSearch(bstRoot, 1); // 반환값은 NULL이거나 1을 가지고 있는 노드의 주소값.

	if (sNode == NULL) // 반환값이 NULL이라는 것은 해당 트리에 찾는 값이 없는 것.
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값 : %d \n", BSTGetNodeData(sNode));

	return 0;
}