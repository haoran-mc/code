#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const long long mod = 1e9 + 7;
LL n, k, ans;

LL work(LL x) {
    LL sum = 0, i = 2, j = 0;

    for ( ; i <= k && i <= x; i = j + 1) {
        printf("n = %lld ", n);
        printf("k = %lld  ", k);
        printf("i = %lld ", i);
        printf("j = %lld  ", j);
        printf("x = %lld ", x);

        LL y = x / i;
        j = min(x / y, k);
        sum = (sum + (j - i + 1) % mod * y % mod) % mod;
        printf("sum = %lld ", sum);
        printf("\n");
    }

    return sum;
}

int main()
{
    scanf("%lld%lld", &n, &k);
    ans = (n + k - 1) % mod;
    ans = (ans + work(n) + work(n - 1)) % mod;

    printf("%lld\n", ans);
    return 0;
}
