#include <iostream>
using namespace std;

class CMyPoint
{
public:
	CMyPoint(int x) // 클래스의 인스턴스가 생성될때 매개변수로 정수 1개만 받았다면 호출됨.
	{
		cout << "CMyPoint(int)" << endl;

		if (x > 100) // 넘겨 받은 x의 값이 100이상이라면 100으로 초기화시킴;
			x = 100;

		m_x = 100;
	}

	CMyPoint(int x, int y) // 매개변수가 두 개 들어왔다면 호출됨.
	{
		cout << "CMyPoint(int, int)" << endl;

		if (y > 200) // 넘겨 받은 두 번째 인자가 200이상이라면 200으로 초기화 시킴
			y = 200;

		m_y = 200;
	}

	void Print()
	{
		cout << "X:" << m_x << endl;
		cout << "Y:" << m_y << endl;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

int main()
{
	CMyPoint ptBegin(110);
	ptBegin.Print();

	CMyPoint ptEnd(50, 250);
	ptEnd.Print();

	return 0;
}
