#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int** A = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}

	int** B = new int* [N];
	for (int i = 0; i < N; i++)
	{
		B[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << A[i][j] + B[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i = 0; i < N; i++)
	{
		delete[] A[i];
	}

	delete[] A;

	for (int i = 0; i < N; i++)
	{
		delete[] B[i];
	}

	delete[] B;


	return 0;
}




// 여기서 사용한 동적 할당은  c에서의 다차원포인터 개념을 기억해보도록 하자.
// '*'이 하나 추가 될 때마다 한 차원씩 증가한다고 생각하자.
// 가장 주의해야 할 점은 다중 포인터 동적 할당하는 순간이 아닌 해제하는 순서를 유의하자 잘못하면 메모리 누수가 생길수도 있다.
// 지금 선언한 순서를 보면 먼저 행을 관리할 포인터를 할당한 후 반복문으로 각 행마다 열 크기만큼 실제 메모리를 할당해주고 있으므로
// 해제 순서는 먼저 각 행의 열 공간들을 먼저 해제 해준 뒤 행을 관리하던 포인터 배열을 해제한다.
// 즉, 쉽게말해서 동적으로 할당해준 선언 순서의 역순으로 해제한다고 생각하자!