// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include "MyString.h"

#include <iostream>
using namespace std;

void TestFunc(const CMyString& param)
{
	cout << param.GetString() << endl;
}

int main()
{
	CMyString strData, strTest;
	strData.SetString("Hello");
	strTest.SetString("World");

	CMyString strNewData(strData);
	cout << strNewData.GetString() << endl;

	strNewData = strTest;
	cout << strNewData.GetString() << endl;


	TestFunc(strData);

	return 0;
}