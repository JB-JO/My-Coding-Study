#include <iostream>
using namespace std;

class value
{
private:
	int N;
public:
	int call(int x, int y)
	{
		N = x * y;
		
		return N;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, A;
	cin >> N;

	int Max = 1, Min = 1000000;

	for (int i = 0; i < N; i++)
	{
		cin >> A;

		if (A > Max)
			Max = A;
		
		if (A < Min)
			Min = A;
	}

	value v;

	cout << v.call(Max, Min) << '\n';


	return 0;
}