#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H, M;
	cin >> H >> M;
	int H2, M2;
	if (M - 45 < 0) {
		M2 = (M + 60) - 45;
		if (H - 1 < 0) {
			H2 = (H - 1) + 24;
			cout << H2 << " " << M2 << '\n';
		}
		else
			cout << H - 1 << " " << M2 << '\n';
	}
	else
		cout << H << " " << M - 45 << '\n';

	return 0;
}
