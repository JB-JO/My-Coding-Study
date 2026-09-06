#include "MergeSort.h"

int MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;  int rIdx = mid + 1;  int i;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));  // 병합 결과를 담을 메모리 공간 할당
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) { // 병합 할 두 영역의 데이터를 비교하여 배열 sortArr에 담음.
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		sIdx++;
	}

	if (fIdx > mid) {  // 배열의 앞 부분이 sortArr로 모두 이동되어 배열 뒷 부분에 남은 데이터를 모두 sortArr로 이동
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {  // 배열의 뒷 부분이 sortArr로 모두 이동되어서 배열 앞 부분에 남은 데이터를 모두 sortArr로 이동
		for (i = fIdx; i <= right; i++, sIdx++) 
			sortArr[sIdx] = arr[i];
	}
	for (i = left; i <= right; i++)  // 병합 결과를 옮겨 담음.
		arr[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)  // left가 작다는 것은 더 나눌 수 있다는 뜻; 
	{		           // Why? 우리는 분할을 더 이상 나눌 수 없는 원자성을 띌 때까지 한다고 했으니 한개만 남게 되면 left와 right값이 같기에 종료되게 된다.
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);  // left ~ mid에 위치한 데이터 정렬
		MergeSort(arr, mid + 1, right); // mid + 1 ~ right에 위치한 데이터 정렬

		MergeTwoArea(arr, left, mid, right);
	}
}