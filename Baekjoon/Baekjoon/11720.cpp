#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string M;
	int temp = 0;
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
		temp += static_cast<int>(M[i] - 48);

	cout << temp << '\n';

	return 0;
}