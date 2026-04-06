#include <iostream>
using namespace std;

class CMyData
{
private:
    int* m_pnData = nullptr;
    
public:
    explicit CMyData(int nParam)
    {
        m_pnData = new int(nParam);
    }

    ~CMyData() { delete m_pnData; }

    operator int() { return *m_pnData; }

    // void로 하지 않고 반환형식을 참조자로 설정한 이유는 l-value의 형식으로 취할 수 없음.
    CMyData& operator=(const CMyData& rhs)
    {
        // r - value가 자신이면 대입을 수행하지 않음.
        if (this == &rhs)
            return *this;

        delete m_pnData;

        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

    CMyData& operator+=(const CMyData& rhs)
    {
        // 현재 값 처리
        int* pnNewData = new int(*m_pnData);

        // 누적할 값 처리
        *pnNewData += *rhs.m_pnData;

        // 이 아래는 기존은 operator= 과 같음 기존 데이터 삭제 후 새 메모리로 대체.
        delete m_pnData;
        m_pnData = pnNewData;

        return *this;
    }
};

int main()
{
    CMyData a(0), b(5), c(10);
    a += b;
    a += c;
    cout << a << endl;

    return 0;
}