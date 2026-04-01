#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a1, a0;
	cin >> a1 >> a0;

	int c;
	cin >> c;

	int n0;
	cin >> n0;

	int fn = a1 * n0 + a0;
	int gn = n0;

	if (a1 <= c && fn <= (c * gn)) 
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}

// 이 문제 처음 제출 시에는 틀렸었음 
// Why?
// 기울기 조건을 넣지 않았음.
// 문제에는 없지만 이런 알고리즘의 시간복잡도 계산문제에서는 함수의 성장속도를 반드시 비교해보자
// 1. 반례 생각하기 -> n이 엄청나게 커져도 과연 식이 맞을지 고민하기
// 2. 극한 개념을 적용 -> 조건의 양변을 n 으로 나눌경우 a1 + a0/n  vs. c -> 즉, a1과 c의 싸움이 된다.
// 3. 제한 사항을 확인하라 -> 이 문제에서는 a0는 음수일 가능성이 있었다!

// 반드시 위의 3개의 사항을 유념해서 문제를 풀자!