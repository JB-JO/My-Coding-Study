#include <iostream>
#include <stdlib.h>
#include "CircularQueue.h"
using namespace std;

CQueue::CQueue()
{
	queue.front = 0;
	queue.rear = 0;

	cout << "Queue()" << endl;
}

CQueue::~CQueue()
{
	cout << "~Queue()" << endl;
}

bool CQueue::QIsEmpty() const
{
	if (queue.front == queue.rear)
		return 1;
	else
		return 0;
}

int NextPosIdx(int pos) // 원형 큐의 핵심. 큐의 다음 위치에 해당하는 배열의 인덱스 값을 반환한다. 큐의 길이보다 하나 작은 값이 전달되면 0을 반환하는데 이는 배열의 끝에 도달 했으므로 앞으로 이동해야 함을 의미하므로 회전을 돕는 핵심적인 함수라 할 수 있다.
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void CQueue::Enqueue(Data data)
{
	if (NextPosIdx(queue.rear) == queue.front)
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	else
	{
		queue.rear = NextPosIdx(queue.rear);
		queue.queArr[queue.rear] = data;
	}
}

Data CQueue::Dequeue()
{
	if (QIsEmpty())
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	else
	{
		queue.front = NextPosIdx(queue.front);
		return queue.queArr[queue.front];
	}
}

Data CQueue::QPeek() const
{
	if (QIsEmpty())
	{
		cout << "Queue Memory Error!" << endl;
		exit(-1);
	}
	else
	{
		int FirstIdx = NextPosIdx(queue.front);
        return queue.queArr[FirstIdx];
	}
}

// 지금 구현한 원형 큐의 경우 0번 인덱스를 사용하지 않음으로써 Empty 상태와 Full 상태의 구분이 가능하다는 이점을 가지게 되는데, 
// 그로 인해서 0번 인덱스는 초기화되지 않은 쓰레기값을 가지고 있음.
// 73번줄의 코드를 return queue.queArr[queue.rear]; 이렇게 할 경우 Dequeue 하기 전이라면 0번 인덱스의 값을 출력해서 원치않는 쓰레기 값을 얻게 되고.
// Dequeue 를 하고 난 후 QPeek을 출력하게 되면 이미 삭제한 인덱스의 값을 출력하게 되는 논리적 오류가 있기 때문에 저렇게 바꿔놓았다.