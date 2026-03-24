#include <stdio.h>
#include "ArrayList.h"

int main(void) {
	List list;
	int data;
	int sum = 0;
	ListInit(&list);

	for (int i = 1; i < 10; i++) {
		LInsert(&list, i);
	}
    
	/*리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산하여 출력한다.*/
	if (LFirst(&list, &data)) {
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("저장된 데이터들의 합: %d\n", sum);

	/*리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제한다.*/
	if (LFirst(&list, &data)) {
		if (data % 2 == 0) {
			LRemove(&list);
		}
		while (LNext(&list, &data))
			if (data % 2 == 0)
				LRemove(&list);
	}

	if (LFirst(&list, &data)) {
		if (data % 3 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
			if (data % 3 == 0)
				LRemove(&list);
	}

	/*저장된 데이터를 순차적으로 출력한다.*/
	printf("현재 저장된 데이터의 수: %d\n", LCount(&list));

		if(LFirst(&list, &data)) {
			printf("%d ", data);

			while (LNext(&list, &data))
				printf("%d ", data);
	    }
		printf("\n\n");
		return 0;
}