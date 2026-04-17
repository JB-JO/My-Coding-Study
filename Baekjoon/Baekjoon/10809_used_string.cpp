#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> Alph(26, -1);

	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++)
	{
		int idx = S[i] - 'a';
		
		if (Alph[idx] == -1)
			Alph[idx] = i;

	}

	for (int x : Alph)
		cout << x << " ";


	return 0;
}
