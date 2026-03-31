#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, temp;
	cin >> N;

	int* Num = new int[N];

	for (int i = 0; i < N; i++)
		cin >> Num[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (Num[i] > Num[j])
			{
				temp = Num[i];
				Num[i] = Num[j];
				Num[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << Num[i] << '\n';

	return 0;
}