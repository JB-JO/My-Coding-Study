#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B;
	cin >> C;

	B += C;
	if (B >= 60)
	{
		A += (B / 60);
		B %= 60;
	}
	if (A >= 24)
		A %= 24;

	cout << A << " " << B << '\n';

	return 0;
}
