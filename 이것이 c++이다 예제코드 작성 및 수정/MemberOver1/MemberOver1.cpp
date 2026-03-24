#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() : m_nData(0) {};

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	void SetData(double dParam) { m_nData = 0; } // int로 선언된 m_nData를 실수를 받으면 0을 출력해서 사용하지 못하게끔 다중 정의

private:
	int m_nData;
};

int main(void)
{
	CMyData t;

	t.SetData(10);
	cout << t.GetData() << endl;

	CMyData h;
	
	h.SetData(5.5);
	cout << h.GetData() << endl;

	return 0;
}
