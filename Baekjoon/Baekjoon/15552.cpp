#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, A, B, i, j;
	cin >> T;
	
	for (i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << '\n';
	}



	return 0;
}