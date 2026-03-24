#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, i;
	cin >> N;

	for (i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << "*";
		
		cout << '\n';
	}
	    

	return 0;
}