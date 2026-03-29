#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char Arr[5][16] = { 0, };

	for (int i = 0; i < 5; i++)
	{
		cin >> Arr[i];
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (Arr[i][j] != '\0')
				cout << Arr[i][j];
		}
	}
	cout << '\n';

	return 0;
}