#include <iostream>
using namespace std;

class CTestData
{
private:
    int m_nData = 0;

public:
    CTestData() { cout << "CTestData()" << endl; }
    ~CTestData() { cout << "~CTestData()" << endl; }

    CTestData(const CTestData& rhs) : m_nData(rhs.m_nData)
    {
        cout << "CTestData(const CTestData &)" << endl;
    }

    // 이동 생성자
    CTestData(CTestData&& rhs) : m_nData(rhs.m_nData)
    {
        cout << "CTestData(CTestData &&)" << endl;
    }
    CTestData& operator=(const CTestData&) = default;

    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }
};

// 여기서 CTestData는 반환형이다.
CTestData TestFunc(int nParam)
{
    cout << "**TestFunc():Begin***" << endl;

    CTestData a;
    a.SetData(nParam);
    cout << "**TestFunc():End*****" << endl;

    return a;
}

int main()
{
    CTestData b;
    cout << "*Before**************" << endl;

    b = TestFunc(20); // 이 코드가 실행되는 순간에 실행 결과에 보이는 것처럼 이동 생성자가 호출된다!
    cout << "*After***************" << endl;
    CTestData c(b);

    return 0;
}

// 즉, 임시 객체가 만들어질 때 복사 생성이 아닌 다른 방법으로 생성이 된 것.
// 복사 생성에서는 "깊은 복사" = 원본과 동일한 사본을 가지며 내용도 같음. 일반적으로 두 배의 메모리 용량이 필요로 한다. 또한 메모리를 복사하는 연산을 반드시 실행해야 한다.
// 이동 생성에서는 "얕은 복사" = 어차피 원본은 곧 소멸하므로 상관없음. 사라질 객체로부터 알맹이는 빼내고 껍데기는 버리는 코드를 만들 수 있음. => 메모리 절반 사용, 복사 연산이 없기에 성능도 올라감.