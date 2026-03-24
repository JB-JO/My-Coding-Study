#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,i;
	cin >> N;

	for (i = 0; i < N / 4; i++)
		cout << "long ";

	cout <<"int" << '\n';


	return 0;
}