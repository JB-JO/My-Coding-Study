#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A;
	int* Check = new int[42] {0, };

	for (int i = 0; i < 10; i++)
	{
		cin >> A;
		Check[A % 42] = 1;
	}

	int count = 0;

	for (int j = 0; j < 42; j++)
	{
		if (Check[j] == 1)
			count++;
	}

	cout << count << '\n';

	delete[] Check;

	return 0;
}