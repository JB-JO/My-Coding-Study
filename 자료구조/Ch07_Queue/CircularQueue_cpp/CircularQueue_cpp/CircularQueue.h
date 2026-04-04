#pragma once
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define QUE_LEN    100
typedef int Data;

class CQueue
{
private:
	struct Queue
	{
		int front; // 출구 
		int rear; // 입구
		Data queArr[QUE_LEN];
	};

	Queue queue;

public:
	CQueue();

	~CQueue();

	bool QIsEmpty() const; // 큐가 비어있는지 아닌지 확인.

	void Enqueue(Data data); // 원형 큐에 데이터 넣기

	Data Dequeue(); // 원형 큐에서 데이터를 리턴하고 삭제시킴.

	Data QPeek() const; // 배열의 해당 인덱스의 값을 리턴하지만 삭제는 하지않는다.
};

#endif // !__C_QUEUE_H__

