#include <iostream>
using namespace std;

int main()
{
	int *pA, *pB;

	pA = new int;
	*pA = 10;

	pB = new int;
	pB = *pA; //여기서 에러가 난다. 둘다 동적으로 생성한 각각의 인스턴스를 가리키는 상태에서 pB가 pA의 인스턴스를 가리키는 상황이 벌어진다.

	cout << *pA << endl;
	cout << *pB << endl;

	delete pA;
	delete pB;

	return 0;
}