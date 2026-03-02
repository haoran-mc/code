#include <cstdio>
int main()
{
    int n;
    int x;
    int y;
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    int xie = x + y;
    int num = 0;
    for (int i = 0; i <= xie; ++i)
        num += i;
    num += x;
    if (x <= 15 || x >= 10)
        printf("%d\n", num);
    else
        printf("%d\n", num - 5);
    return 0;
}
