#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int Val;
	int Max = 0, MaxIndex = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> Val;
		if (Max < Val)
		{
			Max = Val;
			MaxIndex = i + 1;
		}
	}

	cout << Max << '\n';
	cout << MaxIndex << '\n';

	return 0;
}