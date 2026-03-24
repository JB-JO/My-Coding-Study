#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X;
	int A[10000];
	
	cin >> N >> X;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int j = 0; j < N; j++) {
		if (A[j] < X)
			cout << A[j] << " ";
	}

	cout << '\n';


	return 0;
}
