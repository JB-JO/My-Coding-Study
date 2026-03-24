#include <iostream>

class CMyData
{
    int m_nData; //어떠한 접근지시자도 없다면 기본적으로 private: 가 적용된다.

public:
    int GetData(void) { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }
};

int main()
{
    CMyData data;
    data.SetData(10);  //9번줄의 클래스내의 멤버 변수 SetData에 접근해서 m_nData의 값을 10으로 변경한다. 여기서 data.m_nData에 바로 값을 넣는건 불가능하다!
    std::cout << data.GetData() << std::endl; // 8번줄로 이동하여 GetData()를 호출한다.

    return 0;
}

