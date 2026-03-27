#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Name, Grade;
	double credit;
	double totalPoint = 0;
	double totalCredit = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> Name >> credit >> Grade;

		if (Grade == "P") continue;

		totalCredit += credit;
		
		if (Grade == "A+")
			totalPoint += (credit * 4.5);
		else if(Grade == "A0")
			totalPoint += (credit * 4.0);
		else if(Grade == "B+")
			totalPoint += (credit * 3.5);
		else if(Grade == "B0")
			totalPoint += (credit * 3.0);
		else if(Grade == "C+")
			totalPoint += (credit * 2.5);
		else if(Grade == "C0")
			totalPoint += (credit * 2.0);
		else if(Grade == "D+")
			totalPoint += (credit * 1.5);
		else if(Grade == "D0")
			totalPoint += (credit * 1.0);
		else if(Grade == "F" || Grade == "P")
			totalPoint += (credit * 0.0);
	}
	
	cout << fixed; //소수점 형태를 고정 (지수 형태가 아니라 평소 사용하는 일반적인 소수점 형태로 고정)
	cout.precision(6); //출력할 소수점 아래 숫자의 개수를 고정시킨다. (단, fixed를 먼저 쓰지않았을 때에는 출력하는 전체 자릿수를 고정시킨다!)
	cout << totalPoint / totalCredit << '\n';

	return 0;
}