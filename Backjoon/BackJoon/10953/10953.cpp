#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B , T;
	char comma;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> comma>> B;
		cout << A + B << endl;
	}

	return 0;
}