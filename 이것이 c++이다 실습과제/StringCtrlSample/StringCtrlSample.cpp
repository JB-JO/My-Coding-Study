// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include "MyString.h"

#include <iostream>
using namespace std;

void TestFunc(const CMyString& strParam)
{
	cout << strParam << endl;
}

int main()
{
	CMyString strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));


	return 0;
}