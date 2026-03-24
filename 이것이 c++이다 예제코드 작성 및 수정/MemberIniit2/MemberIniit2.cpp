#include <iostream>
using namespace std;

class CTest
{
public:
    CTest()
    {
        cout << "CTest(): 생성자 함수" << endl;
        m_nData = 25;
    }

    int m_nData;

    void PrintData(void)
    {
        cout << m_nData << endl;
    }
};

int main()
{
    cout << "main()함수 시작" << endl;

    CTest t;
    t.PrintData();

    cout << "main()함수 종료" << endl;

    return 0;
}
