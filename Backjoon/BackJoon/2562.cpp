#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int* Arr = new int[9];
	int Max = 0;

	for (int i = 0; i < 9; i++) {
		cin >> Arr[i];
		Max = max(Max, Arr[i]);
	}

	cout << Max << '\n';

	for (int j = 0; j < 9; j++)
		if (Arr[j] == Max)
			cout << j + 1 << '\n';
	
	delete[] Arr;

	return 0;
}