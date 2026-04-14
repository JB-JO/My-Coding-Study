#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	cin >> N >>  X;

	vector<int> v;

	while(N--)
	{
		int a;
		cin >> a;
		if (a < X)
			v.push_back(a);
	}

	for (int j : v)
	{
		cout << j << " ";
	}
	cout << '\n';

	return 0;
}