#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	int i, j, k;

	int* Arr = new int[N + 1] {0, };

	for (int a = 0; a < M; a++)
	{
		cin >> i >> j >> k;
		for (i; i <= j; i++)
			Arr[i - 1] = k;
	}
	
	for (int a = 0; a < N; a++)
		cout << Arr[a] << " ";

	cout << '\n';

	delete[] Arr;

	return 0;
}