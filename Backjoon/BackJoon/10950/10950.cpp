#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, T;
	int i;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << A + B << endl;

	}

	return 0;
}