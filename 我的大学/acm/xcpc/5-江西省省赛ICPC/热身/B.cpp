#include <cstdio>
const int maxn = 90;
typedef long long ill;
#define bug printf("******\n");
ill fibo[maxn];
int main()
{
    fibo[0] = 1;
    fibo[1] = 1;
    int  n;
    scanf("%d", &n);
    for (int i = 2; i <= n+1; ++i)
        fibo[i] = fibo[i-1] + fibo[i-2];
    /*
     *for (int i = 0; i <= n; ++i)
     *    printf("%d\n", fibo[i]);
     */
    printf("%lld\n", fibo[n+1]);
    return 0;
}
