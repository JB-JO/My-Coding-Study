#include <iostream>
#include "MyString.h"
#include "MyStringEx.h"
using namespace std;

void TestFunc(const CMyString& strParam)
{
	cout << strParam[0] << endl;
	cout << strParam[strParam.GetLength() - 1] << endl;
}

int main(void)
{
	//CMyString strLeft("Test"), strRight("String");

	//if (strLeft == strRight)
	//	cout << "Same" << endl;
	//else
	//	cout << "Different" << endl;

	//strLeft = CMyString("String");

	//if (strLeft != strRight)
	//	cout << "Different" << endl;
	//else
	//	cout << "Same" << endl;

	//CMyString strParam("HelloWorld");
	//cout << strParam << endl;
	//TestFunc(strParam);

	CMyStringEx strTest;
	strTest.SetString("I am a boy.");
	cout << strTest << endl;

	int nIndex = strTest.Find("am");
	cout << "Index: " << nIndex << endl;

	return 0;
}