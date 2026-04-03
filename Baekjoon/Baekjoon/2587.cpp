#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int Num[5] = { 0, };
	
	int Value = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> Num[i];
		Value += Num[i];
	}

	sort(Num, Num + 5);

	cout << Value / 5 << '\n';
	cout << Num[2] << '\n';

	return 0;
}
