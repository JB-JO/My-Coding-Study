#include <iostream>
using namespace std;

class CTest
{
	//public 생성자함수 + 소멸자 멤버함수 const선언 내부구현은 멤버 변수를 변경해보자! 또한 그 값을 반환
	//private 지시자로 멤버변수를 선언 초기값은 0으로 한다.
public:
	CTest(int nParam) : m_nData(nParam) {};
	~CTest() {}

	int GetData() const
	{
		m_nData = 20; //const로 선언한 상수형 메서드여도 mutable예약어로 선언한 멤버변수값은 접근 가능하다.

		return m_nData;
	}

private:
	mutable int m_nData = 0;
};

int main()
{
	CTest t(112); //여기서 매개변수로 어떠한 값을 넘김
	cout << t.GetData() << endl; //여기서 GetData()를 호출하면 위에서  어떠한 값을 넘겼던 출력은 GetData 내부에 의해 20이 출력된다.

	return 0;

}