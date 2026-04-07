#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	while (true)
	{
		cin >> n;
		if (n == -1) break;
		
		int* val = new int[n] {0, };

		int x = 0, add = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0 && i != n)
			{
				val[x] = i;
				add += i;
				x++;
			}
		}

		if (add == n) {
			cout << n << " = " << val[0];

			for (int h = 1; h < x; h++)
			{
				if (val[h] != 0)
					cout << " + " << val[h];
			}
			cout << '\n';
		}
		else
			cout << n << " is NOT perfect." << '\n';
		
		delete[] val;
	}

	return 0;
}