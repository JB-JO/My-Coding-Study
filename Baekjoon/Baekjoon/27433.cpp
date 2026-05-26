#include <iostream>
using namespace std;

long long factorial(int N)
{
	if (N == 0)
		return 1;
	else
	{
		return N * factorial(N - 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	cout << factorial(N) << '\n';

	return 0;
}