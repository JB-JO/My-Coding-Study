#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string S;

	cin >> N;

	int count = 0;

	while(N--)
	{
		bool isGroup = true;
		bool Opeared[26] = { false, };

		cin >> S;

		for (int a = 0; a < S.length(); a++)
		{
			if (a > 0 && S[a] != S[a - 1] && Opeared[S[a] - 'a'])
			{
				isGroup = false;
				break;
			}
			Opeared[S[a] - 'a'] = true;
		}
		if (isGroup)
			count++;
	}

	cout << count << '\n';

	return 0;
}