#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i , n, val = 0;
	cin >> n;

	for (i = 1; i < n + 1; i++)
		val = val + i;
	cout << val << '\n';

	return 0;
}
// 또는 { int n; cin>>n; cout<< n*(n+1)/2 << '\n';} 이렇게 메인코드를 짜도 동일하다!