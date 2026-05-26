#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

int main(void) {
	int choice, data;
	Queue pq;
	QueueInit(&pq);

	while (1)
	{
		system("cls");
		printf("\n\n\t\t*** Circular Queue with Array ***\n\n");
		printf("\t\t1.enQueue     2.deQueue     3.Qpeek    4.print     0.exit\n");
		printf("\t\tchoice : [ ]\b\b");
		scanf_s("%d", &choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n\t\tEnter an Integer: ");
			scanf_s("%d", &data);

			enQueue(&pq, data);
			break;

		case 2:
			data = deQueue(&pq);

			printf("\n\n\t\tenQueue data = %d\n", data);
			break;

		case 3:
			data = QPeek(&pq);

			printf("\n\n\t\t QPeek data = %d\n", data);
			break;

		case 4:
			PrintQueue(&pq);
			break;

		case 0:
			exit(0);
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}