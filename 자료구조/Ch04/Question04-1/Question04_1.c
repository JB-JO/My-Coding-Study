#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

int main(void) {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1) {
		printf("정수를 입력하세요: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		newNode->next = head;  //..head->next가 아닌이유는 헤드포인터 자체를 뒤로 미는 식으로 생각하면 쉽다.
		head = newNode;
	}
	printf("\n");

	printf("입력받은 데이터의 전체 출력: \n");
	if (head == NULL) {
		printf("입력받은 데이터가 없습니다. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");


	if (head == NULL) {
		return 0;
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", delNode->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}
