#include <iostream>
using namespace std;

void TestFunc(const int& nParam)
{
    // 상수형 참조 였으나 일반 참조로 형변환 했음
    int& nNewParam = const_cast<int&>(nParam); // 형변환 연산자 const_cast<새형식>(대상) 을 사용

    //따라서 l-value가 될 수 있다.
    nNewParam = 1557;
}

int main()
{
    int nData = 10;

    //상수형 참조로 전달하지만 값이 변경된다.
    TestFunc(nData);

    //변경된 값을 출력한다.
    cout << nData << endl;

    return 0;
}
