#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int Origin[6] = { 1, 1, 2, 2, 2, 8 };
	int input[6];

	for (int i = 0; i < 6; i++)
		cin >> input[i];

	for (int i = 0; i < 6; i++)
		cout << Origin[i] - input[i] << '\n';

	return 0;
}