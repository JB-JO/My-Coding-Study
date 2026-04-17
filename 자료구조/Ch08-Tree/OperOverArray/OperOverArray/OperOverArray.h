#pragma once
#ifndef __OPER_OVER_ARRAY_H__
#define __OPER_OVER_ARRAY_H__

class CIntArray
{
private:
	int* m_pnData;

	int m_nSize;

public:
	CIntArray(int nSize); // 전달된 개수만큼 int 자료를 담을 수 있는 메모리를 확보

	~CIntArray();

	int operator[](int index) const; // 상수형 참조인 경우의 배열 연산자

	int& operator[](int nIndex); // 일반적인 배열 연산자
};

void TestFunc(const CIntArray& arParam);

#endif // !__OPER_OVER_ARRAY_H__
