#include <cstdio>
typedef long long ill;
ill res[30];
int main()
{
    res[3] = 104;
    ill num16 = 32;
    ill num34 = 72;
    for (int i = 4; i <= 25; ++i) {
        res[i] = num16 * 5 + num34 * 6;
        int temp = num16;
        num16 = num16 + 2*num34;
        num34 = 4*temp + 4*num34;
        printf("num16 = %lld\nnum34 = %lld\n\n", num16, num34);
    }
    int n;
    for (n = 3; n <= 25; ++n)
        printf("%lld\n", res[n]);
    //while (scanf("%d", &n) != EOF)
        //printf("%lld\n", res[n]);
    return 0;
}
