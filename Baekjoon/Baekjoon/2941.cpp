#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Alpha;
	
	cin >> Alpha;

	int count = 0;

	for (int i = 0; i < Alpha.length(); i++)
	{
		char cur = Alpha[i];
		char next = Alpha[i + 1];

		if ( i + 1 < Alpha.length() && cur == 'c' && (next == '=' || next == '-'))
			i++;
		else if (cur == 'd')
		{
			if (next == '-')
				i++;
			else if (i+ 2 < Alpha.length() && next == 'z' && Alpha[i + 2] == '=')
				i += 2;
		}
		else if (i + 1 < Alpha.length() && (cur == 'l' || cur == 'n') && next == 'j')
			i++;
		else if (i + 1 < Alpha.length() && (cur == 's' || cur == 'z') && next == '=')
			i++;
		
		count++;
	}

	cout << count << '\n';

	return 0;
}