#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int a = 0; a < N - i; a++)
			cout << " ";
		for (int b = 0; b < 2 * i - 1; b++)
			cout << "*";
		cout << '\n';
	}


	for (int i = N - 1; i >= 1; i--) 
	{ // 아래 역삼각형은 위의 삼각형 코드의 거울 이미지 내부의 for문은 변함없지만 제일 큰 틀은 조건이 바뀌어야함.
		for (int a = 0; a < N - i; a++)
			cout << " ";
		for (int b = 0; b < 2* i - 1; b++)
			cout << "*";
		cout << '\n';
	}

	return 0;
}