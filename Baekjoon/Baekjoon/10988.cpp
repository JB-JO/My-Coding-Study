#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Word;
	cin >> Word;
	int V = 1;
	int val = Word.length() - 1;

	for (int i = 0; i < Word.length() / 2; i++)
	{
		if (Word[i] == Word[val])
			V = 1;
		else
		{
			V = 0;
			break;
		}

		val--;
	}

	cout << V << '\n';

	return 0;
}