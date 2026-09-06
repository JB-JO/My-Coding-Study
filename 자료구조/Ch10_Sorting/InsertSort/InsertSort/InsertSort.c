#include "InsertSort.h"

void InsertSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) // 정렬 대상 저장
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j]; // 비교 대상 뒤로 한칸 밀기
			else
				break;
		}

		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입
	}
}