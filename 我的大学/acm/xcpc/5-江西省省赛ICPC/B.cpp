#include <cstdio>
typedef long long ill;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ill m;
        ill n;
        scanf("%lld", &n);
        scanf("%lld", &m);
        if ((m+1) * m / 2 <= n)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}
