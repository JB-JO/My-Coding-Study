#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, k;
	cin >> N >> k;
	int* numArr = new int[N];

	

	for (int i = 0; i < N; i++)
		cin >> numArr[i];

	sort(numArr, numArr + N, greater<int>());

	cout << numArr[k - 1] << '\n';

	delete[] numArr;

	return 0;
}