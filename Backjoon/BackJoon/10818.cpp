#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int Max;
	int Min;

	cin >> N;

	int* Arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	Max = Arr[0];
	Min = Arr[0];

	for (int j = 1; j < N ; j++)
	{
		Max = max(Max, Arr[j]);

		Min = min(Min, Arr[j]);
	}

	cout << Min << " " << Max << '\n';

	delete[] Arr;

	return 0;
}
