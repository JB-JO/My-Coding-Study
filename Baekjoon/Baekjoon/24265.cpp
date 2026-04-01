#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	cout << ((n - 1) * n) / 2 << '\n';
	cout << 2 << '\n';

	return 0;
}