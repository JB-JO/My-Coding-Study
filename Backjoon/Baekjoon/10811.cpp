#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int i, j, temp;

	int* Arr = new int[N + 1];

	for (int a = 1; a <= N; a++)
		Arr[a] = a;

	for (int a = 0; a < M; a++)
	{
		cin >> i >> j;

		while (i < j)
		{
			temp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = temp;

			i++;
			j--;
		}
	}

	for (int a = 1; a <= N; a++)
		cout << Arr[a] << " ";

	cout << '\n';

	delete[] Arr;

	return 0;
}