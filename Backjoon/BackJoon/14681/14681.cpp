#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x;
	cin >> y;

	if (y > 0)
	{
		if (x > 0)
			cout << "1" << '\n';
		else
			cout << "2" << '\n';
	}
	else if (x < 0 && y < 0)
		cout << "3" << '\n';
	else
		cout << "4" << '\n';

	return 0;
}