#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int Year;
	cin >> Year;

	if ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
		cout<<"1"<<'\n';
	else
		cout << "0" << '\n';

	return 0;
}
