#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string Str;
		cin >> Str;

		cout << Str.front() << Str.back() << '\n';
	}


	return 0;
}