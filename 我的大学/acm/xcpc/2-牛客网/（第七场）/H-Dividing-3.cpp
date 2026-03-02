#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const double epse = 1e-5;
const int mod = 1e9 + 7;

int main()
{
    LL n, k;
    scanf("%lld%lld", &n, &k);
    LL cut = 0, ans = 0;

    //n是k的倍数
    for (int i = 2; i <= k; i = cut + 1) {
        if (i > n)
            break;

        cut = min(n / (n / i), k);
        ans = (ans + (cut - i + 1) * (n / i)) % mod;
    }

    //n-1是k的倍数
    for (int i = 2; i <= k; i = cut + 1) {
        LL ano_n = n - 1;
        if (i > ano_n)
            break;

        cut = min((ano_n) / (ano_n / i), k);
        ans = (ans + (cut - i + 1) * (ano_n / i)) % mod;
    }

    ans = (ans + k - 1) % mod;
    ans = (ans + n) % mod;

    printf("%lld\n", ans);
    return 0;
}
