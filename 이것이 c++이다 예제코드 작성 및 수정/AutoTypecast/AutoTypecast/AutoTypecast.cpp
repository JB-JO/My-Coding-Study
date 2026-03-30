#include <iostream>
using namespace std;

class CTestData
{
public:
    explicit CTestData(int nParam) : m_nData(nParam) {}

    operator int(void) { return m_nData; } // 이 코드 덕분에 24번줄의 코드도 정상적으로 int 자료형으로 변환되어 인식된다. // 형변환 연산자에도 explicit 예약어를 적용할 수 있다. 다만 24번행의 코드를 실행시 묵시적 변환이 불가능 하여 컴파일 오류가 발생한다.

    int GetData()const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main()
{
    CTestData a(10);
    cout << a.GetData() << endl;

    cout << a << endl;
    cout << (int)a << endl; // C스타일의 강제 형변환 즉, 변환할 수 없는 객체라도 강제로 변환시키기에 cpp에서는 사용을 지양하는 것이 좋다.
    cout << static_cast<int>(a) << endl; // cpp스타일의 형변환 적절한 형변환 연산자를 제공치 않으면 강제로 형식을 변환해 주지 않는다.

    return 0;
}
