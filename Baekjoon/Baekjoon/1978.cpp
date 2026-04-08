#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int PnumCount = 0;

	for (int i = 1; i <= N; i++)
	{
		int Num;
		cin >> Num;

		bool PnumIs = true;

		for (int j = 2; j * j <= Num; j++)
		{
			int temp = Num % j;
			if (temp == 0) {
				PnumIs = false;
				break;
			}
			else
				PnumIs = true;
		}
		if (Num != 1 && PnumIs == true)
			PnumCount++;
	}

	cout << PnumCount << '\n';

	return 0;
}