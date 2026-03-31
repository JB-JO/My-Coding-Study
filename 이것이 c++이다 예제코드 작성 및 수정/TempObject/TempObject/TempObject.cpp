#include <iostream>
using namespace std;

class CTestData
{
public:
    CTestData(int nParam, const char* pszName) :m_nData(nParam), m_pszName(pszName)
    {
        cout << "CTestData(int): " << m_pszName << endl;
    }

    ~CTestData()
    {
        cout << "~CTestData(): " << m_pszName << endl;
    }

    CTestData(const CTestData& rhs) : m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
    {
        cout << "CTestData(const CTestData &): " << m_pszName << endl;
    }

    CTestData& operator=(const CTestData& rhs)
    {
        cout << "operator=" << endl;

        m_nData = rhs.m_nData;

        return *this;
    }

    int GetData()const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
    
    const char* m_pszName = nullptr;
};

CTestData TestFunc(int nParam)
{
    CTestData a(nParam, "a");

    return a;
}

int main()
{
    CTestData b(5, "b");
    cout << "*****Begin*****" << endl;

    b = TestFunc(10); // 여기서 임시 객체가 생성되고 소멸함 ( 단, 이름없는 임시 객체의 원본은 임시 객체의 복사 생성이 끝난 후 소멸한다.)
    cout << "*****After*****" << endl;
    cout << b.GetData() << endl;

    return 0;
}

// 또한 52번 행에 b = TestFunc(10); 이 코드는 cout << TestFunc(10).GetData() << endl; 이렇게 변경할 수 있는데, 이렇게 변경하게 되면 둘 다 임시 객체가 생성되고 소멸되기는 하지만 소멸 시점과 함수의 흐름은 달라지게 된다.
// 바꾸게 되면 operator= 이 호출되지 않고 임시객체가 생성된후 그 임시객체로  .GetData()를 호출하고 반환된 int를 cout에 출력 전체 표현식의 끝에서 임시객체는 소멸된다.
