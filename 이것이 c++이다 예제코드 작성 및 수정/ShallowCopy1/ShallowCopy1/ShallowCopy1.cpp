#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData(int nParam)
    {
        m_nData = new int;
        *m_nData = nParam;
    }

    int GetData()
    {
        if (m_nData != NULL)
            return *m_nData;
       
        return 0;
    }

private:
    int* m_nData = nullptr;
};

int main()
{
    CMyData a(10);
    CMyData b(a);
    cout << a.GetData() << endl;
    cout << b.GetData() << endl;

    return 0;
}
// 현재는 메모리를 해제하지 않아서 오류가 발생하지 않지만 만약 소멸자가 들어간다면 이미 해제한 메모리를 다시 해제하는 상황이 벌어져 심각한 오류가 나올 수 있는 코드이다.