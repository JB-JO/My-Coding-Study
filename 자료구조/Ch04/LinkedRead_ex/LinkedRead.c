#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node {
	int data;             //데이터를 담을 공간
	struct _node* next;   //연결의 도구 (다음 노드의 주소를 여기에 저장하게 된다.)
} Node;

int main(void) {
	Node* head = NULL;  //헤드 포인터 즉, 노드의 시작을 알리는 포인터이다.
	Node* tail = NULL;  //테일 포인터 즉, 노드의 끝을 가리키고 있는 포인터이다.
	Node* cur = NULL;   //현재 가리키고 있는 노드를 표현하는 포인터이다.

	Node* newNode = NULL;
	int readData;

	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)   // 1보다 작은 수 즉 정수 기준이기 때문에 0이 입력되는 순간 종료 시켜야한다.
			break;

		newNode = (Node*)malloc(sizeof(Node));  //동적 메모리 할당을 이용하여 노드를 생성한다.
		newNode->data = readData;
		newNode->next = NULL;                //아직 다음 노드는 만들어지지 않았기에 가리키는 노드가 없는 상황이므로 NULL값으로 초기화한다.

		if (head == NULL) {  //헤드포인터가 NULL이라면 노드가 없었다는 의미이므로 첫번째 노드라는 의미가 된다. 즉, 이 첫번째 노드를 헤드포인터가 가리키게 한다.
			head = newNode;
		}
		else                 //두 번째 이후 노드라면
			tail->next = newNode;  //테일포인터가 노드의 끝을 가리키게 한다.

		tail = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL) {
		printf("저장된 자연수가 존재하지 않습니다. \n");  //헤드 포인터가 NULL값을 가지고 있다라는 뜻은 노드가 존재하지 않는다는 의미이므로 저장된 값이 없다고 출력한다.
	}
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);           //현재 가리키고 있는 공간에서 가리키는 주소를 의미하는 next멤버에 NULL값을 가지고 있지 않다는 말은 다음노드가 존재한다는 의미이므로 다음노드로 이동하여 출력시킨다.
		}
	}
	printf("\n\n");

	//동적으로 메모리를 할당 해주었으므로 free함수를 이용하여 해제해주어야 한다.
	if (head == NULL) { //헤드 포인터에 NULL값이 저장되었다는 말은 더이상 해제할 노드가 존재하지 않는다는 의미이므로 return 0 해준다
		return 0;
	}
	else {
		Node* delNode = head;             //새로운 변수에 저장하는 이유는 이렇게 저장하지 아니하고 해제할 경우 다음노드의 주소를 가지고 있는 next도 같이 해제되어 다음노드의 주소를 잃게 되기 때문이다.
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
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

