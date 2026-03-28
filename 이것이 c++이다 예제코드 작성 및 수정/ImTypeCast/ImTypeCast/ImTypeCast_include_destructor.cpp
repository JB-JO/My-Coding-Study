#include <iostream>
using namespace std;

class CTestData
{
public:
    // 매개변수가 하나뿐인 생성자는 형변환이 가능하다! // int 자료형에 대하여 (CTestData(int))를 제공하기 때문에 가능하다!
    CTestData(int nParam) : m_nData(nParam)
    {
        cout << "CTestData(int)" << endl;
    }

    CTestData(const CTestData& rhs) :m_nData(rhs.m_nData) // 변환 생성자 앞에  explicit 예약어를 사용하면 묵시적 변환이 일어나지 않게 하여 임시 객체 생성을 차단할 수 있다!
    {
        cout << "CTestData(const CTestData &)" << endl;
    }

    ~CTestData()
    {
        cout << "~CTestData()" << endl;
    }

    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

void TestFunc(const CTestData &param) // 매개변수가 클래스에 대한 참조 형식이며 묵시적으로 변환 생성된다.
{
    cout << "TestFunc(): " << param.GetData() << endl;
}

int main()
{
    cout << "*****Begin*****" << endl;

    TestFunc(5); // 새로운 CTestData 객체를 생성하고 참조로 전달한다. 
    // 컴파일러가 알아서 임시 객체를 생성한 후 이 임시 객체에 대한 참조가 TestFunc() 함수로 전달되도록 했다. (묵시적 변환) 그리고 이 임시 객체는 반환함과 동시에 소멸 시킴 즉 제작자의 허락없이 컴파일러가 마음대로 객체를 생성하여 프로그램의 효율을 갉아 먹는 원인이 될 수 있다.!
    // 위의 동작 때문에 이 코드는 실제로는 TestFunc(CTestData(5));라고 작성한 것과 같아진 것.

    cout << "******End******" << endl;

    return 0;
}