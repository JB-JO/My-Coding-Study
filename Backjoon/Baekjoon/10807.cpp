#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, v;
	int arr[100];
	int count = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> v;

	for (int j = 0; j < N; j++) {
		if (arr[j] == v)
			count++;
	}
	
	cout << count << '\n';

	return 0;
}
