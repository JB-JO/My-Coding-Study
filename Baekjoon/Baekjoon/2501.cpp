#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> N >> K;

	int x = 0;

	int* numArr = new int[N + 1] {1, };

	int* vla = new int[N] {0, };

	for (int i = 1; i <= N; i++)
	{
		numArr[i] = N % i;

		if (numArr[i] == 0)
		{
			vla[x] = i;
			x++;
		}
	}

	cout << vla[K - 1] << '\n';

	delete[] numArr;
	delete[] vla;

	return 0;
}