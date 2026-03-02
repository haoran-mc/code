#include <cstdio>
#include <algorithm>
const int maxn = 2e5 + 5;
const long long mod  = 998244353;
long long a[maxn];
long long b[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        a[i] = ((i+1) * (n-i)) * a[i];
    }
    for (long long i = 0; i < n; ++i)
        scanf("%lld", &b[i]);
    std::sort(a, a + n);
    std::sort(b, b + n);

    /*for (int i = 0; i < n; ++i)*/
        /*printf("%lld ", a[i]);*/
    /*printf("\n");*/
    /*for (int i = 0; i < n; ++i)*/
        /*printf("%lld ", b[i]);*/
    /*printf("\n");*/

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        /*sum += ((i+1) * (n-i)) * a[i] * b[n-1-i];*/
        sum += a[i] % mod * b[n-1-i] % mod;
        sum %= mod;
        /*printf("%lld\n", ((i+1) * (n-i)) * a[i]);*/
        /*printf("i+1 = %d n-i = %d\n", i+1, n-i);*/
        /*printf("%d * %lld * %lld = ", ((i+1) * (n-i)), a[i], b[n-1-i]);*/
        /*printf("%lld\n", sum);*/
    }
    printf("%lld\n", sum);
    return 0;
}
