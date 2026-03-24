#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() {}

	int m_nData1 = 1557;
	int m_nData2 = 1452;

	void PrintData(void)
	{
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

int main(void)
{
	CTest t;
	t.PrintData();

	return 0;
}