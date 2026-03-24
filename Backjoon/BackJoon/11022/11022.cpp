#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, A, B, x;
	
	cin >> T;
	for (x = 1; x < T + 1; x++) {
		cin >> A >> B;
		cout << "Case " << "#" << x << ": " << A << " + " << B << " = " << A + B << '\n';
	}

	return 0;
}