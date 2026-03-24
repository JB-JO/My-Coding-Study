#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	int Max = -1000001;
	int Min = 1000001;
	int input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		Max = max(Max, input);
		Min = min(Min, input);
	}
	
	cout << Min << " " << Max << '\n';
	
	return 0;
}