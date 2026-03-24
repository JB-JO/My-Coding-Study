#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	CTest(int nParam):m_nData(nParam)
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest::CTest()" << endl;
	}
};

int main()
{
	cout << "Begin" << endl;
	CTest t(1);  //디폴트 생성자(매개변수가 없는 생성자)는 새로운 생성자를 만들면서 생략가능하다. 즉 CTest클래스는 매개변수를 넘겨주어야 생성가능하다.
	cout << "Before h" << endl;
	CTest h(2);
	cout << "END" << endl;// 소멸자는 객체가 소멸하는 순간에는 다양성이 없기때문에 다중 정의가 불가능하다.

	return 0;
}
