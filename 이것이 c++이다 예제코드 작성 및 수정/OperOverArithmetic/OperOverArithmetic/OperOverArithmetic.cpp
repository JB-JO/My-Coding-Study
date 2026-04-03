#include <iostream>
using namespace std;

class CMyData
{
private:
    int m_nData = 0;

public:
    CMyData(int nParam) :m_nData(nParam)
    {
        cout << "CMyData(int)" << endl;
    }

    ~CMyData() { cout << "~CMyData()" << endl; }

    CMyData(const CMyData& rhs) :m_nData(rhs.m_nData)
    {
        cout << "CMyData(const CMyData &)" << endl;
    }

    CMyData(const CMyData&& rhs) :m_nData(rhs.m_nData)
    {
        cout << "CMyData(const CMyData &&)" << endl;
    }

    operator int() { return m_nData; }

    CMyData operator+(const CMyData& rhs)
    {
        cout << "operator+" << endl;
        CMyData result(0);
        result.m_nData = this->m_nData + rhs.m_nData;

        return result;
    }

    CMyData operator=(const CMyData& rhs)
    {
        cout << "operator=" << endl;
        m_nData = rhs.m_nData;

        return *this;
    }
};

int main()
{
    cout << "*****Begin*****" << endl;
    CMyData a(0), b(3), c(4);

    a = b + c; // b + c 연산에서 이름없는 임시 객체가 생성되고 이 임시 객체가 a에 값을 대입한다.
    // 덧셈 연산에서 이동 생성자가 호출된다.

    cout << a << endl;
    cout << "******End******" << endl;

    return 0;
}


// a = b + c; 이 코드는 매우 간단해 보이지만 다르게 작성하면
// a = b.operator+(c);
// a.operator=(b.operator+(c)); 
// 위와 같게 작성해야 한다.
// 또한 반환 형식은 CMyData& 형식이 되지 못하고 그냥 CMyData 형식이 된다.

// 연산자 함수도 다중 정의 할 수 있다.
// 예를 들어 CMyData +int의 형식을 지원하고 싶다면
// CMyData operator+(int nParam); 이렇게 만들면된다.

// 절대 Never 만약도 안되 그냥 안되
// "논리 연산자들을 다중 정의 해서는 안된다!"