/* *
 *  1, 1
 *  1, 2
 *  1, 3
 *  2, 1
 *  3, 1
 *  2, 2
 *  3, 2
 *  3, 3
 */

#include <cstdio>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;
long long n, k, ans;

void find(long long n) {
    long long i, j;

    for(i = 2; i <= n && i <= k; i = j + 1)
    {
        j = min(n / (n / i), k);
        (ans += (j - i + 1) % mod * (n / i) % mod ) %= mod;
    }
}

int main()
{
    scanf("%lld%lld", &n, &k);
    find(n);
    find(n-1);

    printf("%lld\n", (ans + n + k - 1) % mod);
    return 0;
}
