#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, V;
	cin >> A >> B >> V;

	int D;
    if ((V - A) % (A - B) != 0)
		D = (V - A) / (A - B) + 2;
	else
		D = (V - A) / (A - B) + 1;

	cout << D << '\n';

	return 0;
}