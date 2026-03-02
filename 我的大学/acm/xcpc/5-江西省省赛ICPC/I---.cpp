#include <cstdio>
typedef long long ill;
#define bug prillf("*****\n");
int main()
{
    ill n;
    ill x;
    ill y;
    scanf("%lld", &n);
    scanf("%lld", &x);
    scanf("%lld", &y);
    ill xie = x + y + 1;
    ill num = 0;
    if (xie <= n) {
        for (ill i = 0; i < xie; ++i)
            num += i;
        num += x;
    }
    else {
        for (ill i = 0; i < n; ++i)
            num += i;
        ill j;
        ill i = 0;
        for (j = n; i < xie-n; --j, ++i)
            num += j;
        num += (x-xie+n);
    }
    if (num >= 10 && num <= 16)
        printf("%lld\n", num);
    else if (num > 16)
        printf("%lld\n", num);
    else
        printf("%lld\n", num);
    return 0;
}
