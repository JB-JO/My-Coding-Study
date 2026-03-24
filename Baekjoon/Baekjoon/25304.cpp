#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X, N, i, a, b, Add = 0;

	cin >> X;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> a >> b;
		Add += (a * b);
	}
	if (X == Add)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';

	return 0;
}
