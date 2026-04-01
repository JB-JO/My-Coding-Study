#include <iostream>
using namespace std;

int main()
{
	int&& data = 3 + 4; // r-value 참조자 기존 참조자와 다르게 &&가 두번 붙는다.

	cout << data << endl;

	data++;

	cout << data << endl;


	return 0;
}
// r-value 란 '연산에 따라 생성된 임시 객체'