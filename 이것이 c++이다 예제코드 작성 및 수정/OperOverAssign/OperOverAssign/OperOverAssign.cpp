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

    void operator=(const CMyData& rhs)
    {
        delete m_pnData;

        m_pnData = new int(*rhs.m_pnData);
    }
};

int main()
{
    CMyData a(0), b(5);
    a = b;
    cout << a << endl;

    return 0;
}

// 23번 행의 코드의 경우 
//M_pnData = new int;
//*m_pnData = *rhs.m_pnData;
//이렇게 두 줄의 코드로 변경이 가능하다.

// 30번 행의 코드를 a = a;로 변경하면 문법적으로는 문제가 없지만 논리적으로 심각한 오류를 경험할 수 있음.
// 본래는 0이 출력되어야 하지만 쓰레기값이 출력되는 이유는 데이터 복사 전에 원본을 삭제하기 때문이다.
// 위의 이유로 보통 단순 대입 연산자의 내부는 this == &rhs 인 r-value인 경우 대입을 수행하지 않는다.

// 또한 c라는 인스턴스를 생성하고 a = b = c 같은 코드를 사용하게 되면 오류가 발생하는데,
// void를 l-value의 형식으로 취할 수 없을 뿐 아니라 존재하지도 않는 것을 대입한다는 것 자체가 논리적으로 맞지 않기 때문이다.
// 보통 대입 연산자 함수의 반환 형식을 참조자로 설정해서 문제를 해결한다.
