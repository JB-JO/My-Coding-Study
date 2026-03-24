#include <cstdio>

#define ADD(a, b)((a) + (b))

int Add(int a, int b)
{
    return a + b;
}

inline int AddNew(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;
    printf("정수 두 개를 입력하세요: ");
    scanf_s("%d%d", &a, &b);
    printf("입력받은 정수는 현재: %d, %d 입니다.\n", a, b);

    printf("ADD(): %d\n", ADD(a, b));
    printf("Add(): %d\n", Add(a, b));
    printf("AddNew(): %d\n", AddNew(a, b));

    return 0;
}