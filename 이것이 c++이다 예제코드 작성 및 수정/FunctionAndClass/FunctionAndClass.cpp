#include <iostream>
using namespace std;

class CTestData
{
private:
	int m_nData = 0;

public:
	CTestData(int nParam) :m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}

	CTestData(const CTestData& rhs) :m_nData(rhs.m_nData)  // 여기서 CTestData(const CTestData &rhs) = delete; 라고 쓰면 코드의 성능이 나빠 지는 문제를 문법적으로 차단 가능하다.
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	int GetData() const { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }
};

void TestFunc(CTestData param) // 코드 자체는 문제없지만 이함수의 호출이 TestFunc(a)로 되어서 쓸데없이 객체가 두 개가 된다.
{ // void TestFunc(CTestData &Param) 처럼 참조자를 이용하면 '값에 의한 호출'인지 '참조에 의한 호출'인지 사용자 코드에서 명확하게 알 수 있게된다.
	cout << "TestFunc()" << endl;

	param.SetData(25);
}

int main()
{
	cout << "*****Begin*****" << endl;
	CTestData a(35);
	TestFunc(a);

	cout << "a: " << a.GetData() << endl;

	cout << "******End******" << endl;

	return 0;
}
