#include <iostream>
using namespace std;

void TestFunc(int&& rParam)
{
    cout << "TestFunc(int &&)" << endl;
}

void TestFunc(int nParam)
{
    cout << "TestFunc(int)" << endl;
}

int main()
{
    TestFunc(3 + 4); // 바로 오류가 나는걸 알 수 있다. 왜? -> 위의 두 개의 함수 모두 매개변수로 3 + 4를 받을 수 있기 때문이다. 즉 모호성이 발생한 것.
    return 0;
}

