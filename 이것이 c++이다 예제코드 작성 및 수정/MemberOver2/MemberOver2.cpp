#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() : m_nData(0) {};

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	void SetData(double dParam) = delete; // 실수를 쓰지 못하게끔 그냥 삭제 삭제해버림


private:
	int m_nData;
};

int main(void)
{
	CMyData x;
	x.SetData(25);
	cout << x.GetData() << endl;

	CMyData y;
	y.SetData(17.2); // C2280 "삭제된 함수를 참조하려고 합니다."라는 오류를 띄움
	cout << y.GetData() << endl;

	return 0;
}