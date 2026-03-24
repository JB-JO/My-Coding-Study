#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);

	//멤버 읽기만 수행하므로 메서드를 상수화한다.
	//상수형 메서드는 절대로(혹은 문법적으로) 멤버 변수의 값을 쓸 수 없고, 상수형 메서드가 아닌 멤버는 호출할 수 없다.
	//형한정어 const는 계단의 난간과 같으니 적극적으로 사용할 수 있도록 생각하고 또 생각해보자!
	const char* GetString() const;

	void Release();
};

