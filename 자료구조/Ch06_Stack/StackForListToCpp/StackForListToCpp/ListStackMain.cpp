#include <iostream>
#include "ListStack.h"
using namespace std;

int main(void)
{
	ListStack stack;

	stack.SPush(1); stack.SPush(2);
	stack.SPush(3); stack.SPush(4);
	stack.SPush(5);

	cout << "스택의 마지막 데이터: ";
	cout << stack.SPeek() << endl;

	while (!stack.SIsEmpty())
		cout << "스택에 저장된 마지막 데이터는: "<< stack.SPop() << endl;

	return 0;
}