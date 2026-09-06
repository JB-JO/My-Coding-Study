

int ISearch(int ar[], int first, int last, int target)
{
	int mid;

	if (ar[first] > target || ar[last] < target)
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}



// 이전 이진탐색의 탈출 조건이었던 if(first > last)를 그대로 사용할 시 탐색 대상이 존재하지 않는 경우에 
// 재귀적 호출됨에 따라 first와 last가 가리키는 값의 범위를 넘어서 무한루프에 빠지는 오류가 발생하기에 위의 조건으로 변경해야한다.