#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData() { cout << "CMyData()" << endl; }
    int GetData() { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

protected:
    void PrintData() { cout << "CMyData::PrintData()" << endl; }

private:
    int m_nData = 0;
};

class CMyDataEx :public CMyData
{
public:
    CMyDataEx() { cout << "CMyDataEx()" << endl;}
    void TestFunc()
    {
        PrintData();
        SetData(5);
        cout << CMyData::GetData() << endl;
    }
};


int main()
{
    CMyDataEx data;

    data.SetData(10);
    cout << data.GetData() << endl;

    data.TestFunc();

    return 0;
}


// 상속 관계에서 파생 클래스의 생성자는 먼저 호출되지만 실행은 나중에 된다.
// 실행 시키면 알수 있지만 부모 클래스에서 private: 접근제어지시자를 사용하여 선언한 멤버는 파생 클래스에서 접근이 불가하다.