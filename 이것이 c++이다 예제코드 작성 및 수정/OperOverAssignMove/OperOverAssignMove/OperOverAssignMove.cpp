#include <iostream>
#include "OperOverAssignMove.h"
using namespace std;

CMyData::CMyData(int nParam) // explicit 는 선언에서만 사용하고 구현하는 단계에서는 붙이지 않는다.
{
	cout << "CMyData(int)" << endl;
	m_pnData = new int(nParam);
}

CMyData::CMyData(const CMyData& rhs)
{
	cout << "CMyData(const CMyData &)" << endl;
	m_pnData = new int(*rhs.m_pnData);
}

CMyData::~CMyData()
{
	delete m_pnData;
}

CMyData::operator int()
{
	return *m_pnData;
}

CMyData CMyData::operator+(const CMyData& rhs)
{
	return CMyData(*m_pnData + *rhs.m_pnData);
}

CMyData& CMyData::operator=(const CMyData& rhs)
{
	cout << "operator=" << endl;
	if (this == &rhs)
		return *this;

	delete m_pnData;
	m_pnData = new int(*rhs.m_pnData);

	return *this;
}

CMyData& CMyData::operator=(CMyData&& rhs)
{
	cout << "operator=(Move)" << endl;

	m_pnData = rhs.m_pnData;
	rhs.m_pnData = NULL;

	return *this;
}


// a = b + c; 와 a = b; 를 비교해보아야 한다.
// b와 c를 더하면 당연히 operator+ 함수가 호출되고 부산물로 임시 객체가 탄생함.
// 이 임시 객체를 r-value 삼아 곧바로 단순 대입 연산을 실행한다면 이때는 이동 대입 연산자가 호출된다.
// 다만 이동 대입 연산자를 다중 정의하지 않는다면 일반 대입 연산자 함수가 호출되지만 존재한다면 컴파일러가 이동대입 연산자를 호출해 준다.
// 이동 시멘틱은 이동 생성자와 이동 대입 연산자로 구현된다.
// 둘 모두 곧 사라질 임시 객체와 관련된 것.
// 언제 어느 조건에서 호출되는지 정확히 알고 사용하는 것이 중요하다.!