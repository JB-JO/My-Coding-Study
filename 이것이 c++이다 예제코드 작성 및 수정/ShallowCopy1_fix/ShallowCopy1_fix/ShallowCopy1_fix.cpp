#include <iostream>
using namespace std;

class CMyData
{
private:
    int* m_pnData = nullptr;

public:
    CMyData(int nParam)
    {
        m_pnData = new int;
        *m_pnData = nParam;
    }

    //복사 생성자 선언 및 정의 추가
    CMyData(const CMyData& rhs)
    {
        cout << "CMyData(const CMyData &)" << endl;

        m_pnData = new int;

        // 포인터가 가리키는 위치에 값을 복사한다.
        *m_pnData = *rhs.m_pnData;
    }

    ~CMyData()
    {
        delete m_pnData;
    }

    int GetData()
    {
        if (m_pnData != NULL)
            return *m_pnData;

        return 0;
    }

};

int main()
{
    CMyData a(10);
    CMyData b(a);
    cout << a.GetData() << endl;
    cout << b.GetData() << endl;

    return 0;
}
