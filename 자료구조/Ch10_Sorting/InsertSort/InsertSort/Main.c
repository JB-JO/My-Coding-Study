#include <stdio.h>
#include "InsertSort.h"

int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InsertSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}