#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int* Arr = new int[31] {0, };

	for (int i = 0; i < 28; i++) { //Arr배열의 인덱스 번호 1번부터 30번까지 중에 입력을 28번 받고 어짜피 30이하의 수가 입력되니 n을 인덱스로 사용해서 값이 존재한다는 의미로 1로 변경
		cin >> n;
		Arr[n] = 1;
	}
	for (int j = 1; j < 31; j++) { // Arr배열을 1번인덱스부터 쭉돌아서 0이 있는 인덱스 번호를 출력 이렇게 하면 결국 두 번 출력을 작은 숫자부터 출력하게됨
		if (Arr[j] == 0)
			cout << j << '\n';
	}
		
	delete[] Arr;

	return 0;
}