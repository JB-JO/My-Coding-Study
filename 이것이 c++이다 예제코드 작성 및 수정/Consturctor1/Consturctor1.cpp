#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() //생성자 함수로 클래스의 인스턴스가 생성되면 함수가 호출된다.
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest() //클래스의 인스턴스가 사라지면 소멸자 함수가 호출된다.
	{
		cout << "~CTest::CTest()" << endl;
	}
};

int main()
{
	cout << "Beging" << endl;
	CTest a;
	cout << "END" << endl;

	return 0;
} //여기서 클래스 인스턴스인 a가 종료되므로 소멸자함수가 호출된다.

