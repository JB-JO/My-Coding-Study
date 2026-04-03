#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int count[10001] = { 0, }; // 초깃값을 0으로 초기화하는 이유는 이 배열의 내부 값만큼 해당 인덱스를 출력하기 위함이다.

	for (int i = 0; i < N; i++) // 여기서 num에 입력받은 숫자를 그대로 배열의 인덱스로 사용하고, 해당 인덱스의 값을 하나씩 늘려준다.
	{
		int num;
		cin >> num;
		count[num]++;
	}

	for (int i = 1; i <= 10000; i++) // 배열을 돌면서 해당 인덱스의 값 즉, 해당 인덱스 숫자를 입력받은 만큼 출력하고 다음으로 넘어가는 반복문이다.
		for (int j = 0; j < count[i]; j++)
			cout << i << '\n';


	return 0;
}

// 이 문제에서 핵심은 DAT (Direct Address Table)의 개념을 아는지 모르는지인거 같다.
// DAT란 "값을 배열의 인덱스로 직접 사용하는 테이블"