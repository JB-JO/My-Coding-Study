#include <stdio.h>
#include "BubbleSort.h"

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}