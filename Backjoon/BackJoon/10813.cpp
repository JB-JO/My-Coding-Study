#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int* Arr = new int[N + 1];

	for (int a = 1; a <= N; a++)
		Arr[a] = a;

	int i, j;

	for (int b = 0; b < M; b++)
	{
		cin >> i >> j;

		int vs = Arr[i];

		Arr[i] = Arr[j];
		Arr[j] = vs;
	}

	for (int b = 1; b <= N; b++)
		cout << Arr[b] << " ";

	cout << '\n';

	delete[] Arr;

	return 0;
}