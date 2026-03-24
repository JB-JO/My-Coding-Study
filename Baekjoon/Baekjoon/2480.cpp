#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C, R;
	cin >> A >> B >> C;

	if (A == B && B == C)
	{
		R = 10000 + (A) * 1000;
		cout << R << '\n';
	}
	else if (A == B || A == C || B == C) {
		int same;
		if (A == B) same = A;
		else if (B == C) same = B;
		else same = A;
		R = 1000 + (same * 100);

		cout << R << '\n';
	}
	else {
		int maxVal = max(A, max(B, C));
		R = maxVal * 100;

		cout << R << '\n';
	}


	return 0;
}

