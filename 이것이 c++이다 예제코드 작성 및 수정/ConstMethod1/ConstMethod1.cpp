#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam) :m_nData(nParam) {};
	~CTest() {}

	int GetData() const //상수형 메서드로 정의 (this 포인터를  상수형 포인터로 변경하는 방법)
	{
		return m_nData; // 멤버 변수의 값을 변경하거나 쓸 수 없음. 상수형 메서드가 아닌 멤버는 호출할 수 없음.
	}

	int SetData(int nParam) {
		m_nData = nParam;
	}

private:
	int m_nData = 0;
};

int main()
{
	CTest t(10);
	cout << t.GetData() << endl;

	return 0;
}
// c++ 에서 const가 가지는 의미는 계단의 '난간'과 같다.
// 할 수만 있다면 const 선언을 할 수 있는 한 const를 사용하자.!