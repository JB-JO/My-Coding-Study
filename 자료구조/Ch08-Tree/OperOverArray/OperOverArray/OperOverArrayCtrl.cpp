#include <iostream>
#include "OperOverArray.h"
using namespace std;

int main(void)
{
	CIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = i * 10;

	TestFunc(arr);

	return 0;
}