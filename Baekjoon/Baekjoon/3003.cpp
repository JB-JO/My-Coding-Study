#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, Q, L, B, N, F;
	cin >> K >> Q >> L >> B >> N >> F;

	if (K > 0)
		K = (-K) + 1;
	else if (K < 0)
		K = abs(K) - 1;
	else
		K = 1;

	if (Q > 0)
		Q = (-Q) + 1;
	else if (Q < 0)
		Q = abs(Q) - 1;
	else
		Q = 1;

	if (L > 0)
		L = (-L) + 2;
	else if (L < 0)
		L = abs(L) - 2;
	else
		L = 2;

	if (B > 0)
		B = (-B) + 2;
	else if (B < 0)
		B = abs(B) - 2;
	else
		B = 2;

	if (N > 0)
		N = (-N) + 2;
	else if (N < 0)
		N = abs(N) - 2;
	else
		N = 2;

	if (F > 0)
		F = (-F) + 8;
	else if (F < 0)
		F = abs(F) - 8;
	else
		F = 8;

	cout << K << " " << Q << " " << L << " " << B << " " << N << " " << F << '\n';

	return 0;
}