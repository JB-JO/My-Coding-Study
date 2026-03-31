#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int* Num = new int[N];

	for (int i = 0; i < N; i++)
		cin >> Num[i];

	sort(Num, Num + N);

	for (int i = 0; i < N; i++)
		cout << Num[i] << '\n';

	delete[] Num;

	return 0;
}