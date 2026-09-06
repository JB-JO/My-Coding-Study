#include <stdlib.h>
#include "QuickSort.h"

int Swap(int arr[], int low, int high)
{
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];  // 피벗 위치를 가장 왼쪽으로 지정
	int low = left + 1;
	int high = right;
	
	while (low <= high)  // 교차되지 않을 때까지 반복
	{
		while(pivot > arr[low] && low <= right)  // 피벗보다 큰 값을 찾는 과정
			low++;
		while (pivot < arr[high] && high >= (left + 1))  // 피벗보다 작은 값을 찾는 과정
			high--;
		if (low <= high)
			Swap(arr, low, high); // 만약 교차되지 않은 상태라면 Swap 실행.
	}

	Swap(arr, left, high); // 피벗과 high가 가리키는 대상 교환
	return high;  // 옮겨진 피벗의 위치정보를 반환함.
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}