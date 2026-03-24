#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	int TotalTime = 0;

	for (int i = 0; i < S.length(); i++)
	{
		switch (S[i])
		{
		case 'A': case 'B': case 'C' :
			TotalTime += 3;
			break;
		case 'D': case 'E': case 'F':
			TotalTime += 4;
			break;
		case 'G' : case 'H' : case 'I':
			TotalTime += 5;
			break;
		case 'J': case 'K': case 'L':
			TotalTime += 6;
			break;
		case 'M': case 'N': case 'O':
			TotalTime += 7;
			break;
		case 'P': case 'Q': case 'R': case 'S':
			TotalTime += 8;
			break;
		case 'T': case 'U': case 'V':
			TotalTime += 9;
			break;
		case 'W': case 'X': case 'Y': case 'Z':
			TotalTime += 10;
			break;
		}
	}

	cout << TotalTime << '\n';

	return 0;
}