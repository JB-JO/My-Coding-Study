#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int count = 0;

	int Paper[100][100] = { 0, };

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int a = x; a < x + 10; a++)
		{
			for (int b = y; b < y + 10; b++)
				Paper[a][b] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if(Paper[i][j] == 1)
				count++;
		}
	}

	cout << count << '\n';

	return 0;
}