#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int Arr[10][10];
	int Max = 0;
	int Row, Column;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> Arr[i][j];

			Max = max(Max, Arr[i][j]);
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (Arr[i][j] == Max) {
				Row = i;
				Column = j;
			}
		}
	}
	
	cout << Max << '\n';
	cout << Row << " " << Column << '\n';

	return 0;
}
