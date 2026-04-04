#include <iostream>
#include "CircularQueue.h"
using namespace std;

int main(void)
{
	CQueue q;

	q.Enqueue(1); q.Enqueue(5);
	q.Enqueue(5); q.Enqueue(7);
	q.Enqueue(1557);

	cout << q.QPeek() << endl;

	while (!q.QIsEmpty())
		cout << q.Dequeue() << endl;

	return 0;
}