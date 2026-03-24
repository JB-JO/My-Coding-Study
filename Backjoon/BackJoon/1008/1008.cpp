#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double A, B;

	cin >> A >> B;

	double Value = A / B;

	cout << fixed;
	cout.precision(9);

	cout << Value << '\n';

	return 0;
}