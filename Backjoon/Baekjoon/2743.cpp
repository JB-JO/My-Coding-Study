#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Str;
	
	cin >> Str;

	int len = Str.length();

	cout << len << '\n';

	return 0;
}