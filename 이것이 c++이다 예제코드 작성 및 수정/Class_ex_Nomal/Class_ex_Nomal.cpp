#include <iostream>
using namespace std;

class USERDATA
{
public:
    int nAge;
    char szName[32];

    void Print(void)
    {
        printf("%d, %s\n", nAge, szName);
    }
};



int main()
{
    USERDATA user = { 18, "특수반 주먹이"};
    user.Print();

    return 0;
}
