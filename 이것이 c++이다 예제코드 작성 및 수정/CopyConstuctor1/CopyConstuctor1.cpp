#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }

	CMyData(const CMyData& rhs)
		// :m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyData(const CMyData &)" << endl;
	}

	int GetData(void) const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main()
{
	CMyData data;
	data.SetData(10);

	CMyData b(data);
	cout << b.GetData() << endl;

	return 0;
}