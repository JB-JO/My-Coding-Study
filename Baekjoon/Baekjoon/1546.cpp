#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	double temp = 0;
	double Max = 0;
	cin >> N;

	double* Score = new double[N];
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		Score[i] = M;
		if (Max < M)
			Max = M;
	}

	for (int i = 0; i < N; i++)
	{
		Score[i] = (Score[i] / Max) * 100;
		temp += Score[i];
	}


	cout << fixed;
	cout.precision(6);
	cout << temp / N << '\n';

	delete[] Score;

	return 0;
}