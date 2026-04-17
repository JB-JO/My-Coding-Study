#include <iostream>
#include "OperOverArray.h"
using namespace std;

CIntArray::CIntArray(int nSize)
{
	m_pnData = new int[nSize];
	memset(m_pnData, 0, sizeof(int) * nSize);
}

CIntArray::~CIntArray()
{
	delete m_pnData;
}

int CIntArray::operator[](int nIndex)const
{
	cout << "operator[] const" << '\n';
	return m_pnData[nIndex];
}

int& CIntArray::operator[](int nIndex)
{
	cout << "operator[]" << endl;
	return m_pnData[nIndex];
}
void TestFunc(const CIntArray& arParam)
{
	cout << "TestFunc()" << endl;

	cout << arParam[3] << endl;
}