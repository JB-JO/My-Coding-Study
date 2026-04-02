#include "MyString.h"
#include <iostream>
using namespace std;

CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{
}

CMyString::~CMyString()
{
	//객체가 소멸하기 전에 메모리를 해제한다.
	Release();
}

CMyString::CMyString(const char* pszParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(pszParam);
}

CMyString::CMyString(const CMyString& rhs)
	:m_pszData(NULL)
	,m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	cout << "CMyString 이동 생성자 호출" << endl;

	// 얕은 복사를 수행해도 상관없다 why? 원본은 어짜피 곧 사라진다.
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들은 초기화한다. 절대로 해제하면 안된다!
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

int CMyString::SetString(const char* pszParam)
{
	//객체가 소멸하기 전에 메모리를 해제한다.
	//아래의 Release()메소드 호출을 가장 먼저 한거 자체가 재호출을 대비하는 것!
	Release();

	//NULL을 인수로 함수를 호출했다는 것은 메모리를 해제하고 NULL로 초기화하는 것으로 볼 수 있다.
	//NULL을 인수로 함수를 호출했다는 것은 인수가 존재하지 않는 것이므로 메모리가 필요하지 않다는 의미이다.
	if (pszParam == NULL)
		return 0;

	//길이가 0인 문자열도 초기화로 인식하고 처리한다.
	//길이가 0인 문자열 또한 NULL초 초기화하는 것으로 볼 수 있으므로 아래의 코드를 작성해야한다.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	//문자열의 끝인 NULL 문자를 고려해 메모리를 할당한다.
	//당연히 문자열을 저장해야하는 메모리이니까 new로 동적할당시 배열로 할당해주어야한다.
	m_pszData = new char[nLength + 1];

	//새로 할당한 메모리에 문자열을 저장한다.
	//strcpy와 하는 동작은 동일하지만 두번째 인자로 버퍼크기를 명시해서 조금 더 안전하게 사용가능함. 
	//현재 두번째 인자로 들어가있는 sizeof(char)*(nLength +1)은 1 * (nLength + 1) 즉 그냥 nLength + 1 과 동일함.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;


	return nLength;
}

const char* CMyString::GetString() const
{
	// TODO: 여기에 구현 코드 추가.
	return m_pszData;
}

void CMyString::Release()
{
	// 그냥 조건문없이 바로 delete[] m_pszData;로 적어도 문제는 없지만 NULL값을 확인하는 과정을 넣어 조금더 안전하게 해제하기 위함.
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	//자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

