#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, T;
	int i = 1;

	cin >> T;

	for (i; i - 1 < T; i++)
	{
		cin >> A >> B;
		cout << "Case " << "#" << i << ": " << A + B << endl;
	}

	return 0;
}
