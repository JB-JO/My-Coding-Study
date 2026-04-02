// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include "MyString.h"

#include <iostream>
using namespace std;

CMyString TestFunc(void)
{
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;

	return strTest;
}

int main()
{
	TestFunc(); // 이름없는 임시 객체가 만들어진다.


	return 0;
}