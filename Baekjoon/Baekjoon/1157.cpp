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

	int Alphabet[26]{ 0, };

	int Max = 0;
	int index = 0;
	bool isDupl = false; // 이렇게 중복인지 아닌지 케이스가 단 두가지 일때는 bool을 이용하자!
	

	transform(S.begin(), S.end(), S.begin(), ::toupper);

	for (int i = 0; i < S.length(); i++)
		Alphabet[S[i] - 'A'] += 1;

	for (int a = 0; a < 26; a++)
	{

		if (Max < Alphabet[a])
		{
			Max = Alphabet[a];
			index = a;
			isDupl = false;
		}
		else if (Alphabet[a] == Max && Max != 0)
		{
			isDupl = true;
		}
	}

	if (isDupl)
		cout << "?" << '\n';
	else
		cout << static_cast<char>(index + 'A') << '\n';

	return 0;
}