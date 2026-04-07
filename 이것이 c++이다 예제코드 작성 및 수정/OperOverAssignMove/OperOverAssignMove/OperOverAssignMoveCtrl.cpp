#include <iostream>
#include "OperOverAssignMove.h"
using namespace std;

int main(void)
{
	CMyData a(0), b(3), c(4);

	cout << "*+***Before*****" << endl;

	a = b + c;
	cout << "*****After*****" << endl;

	cout << a << endl;

	a = b;
	cout << a << endl;

	return 0;
}