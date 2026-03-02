#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1e6;
const int inf  = 0x3f3f3f3f;
const int mod  = 1e9 + 7;
vector <long long> fact(maxn + 5, 1LL);
vector <long long> inv(maxn + 5, 1LL);
int res[maxn];

int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return res;
}

void Fcat(int n) {
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = binPow(fact[i], mod - 2);
    }
}

int C(int k, int n, const vector <long long> &fact, const vector <long long> &inv) {
    if (k > n) return 0;
    int multiply = (1LL * fact[n] * inv[k]) % mod;
    multiply = (1LL * multiply * inv[n - k]) % mod;
    return multiply;
}

int main() {
    int m;
    scanf("%d", &m);
    if (m == 2) {
        printf("1");
        return 0;
    }
    Fcat(m);
    for (int n = 3; n <= m; ++n) {
        int num = C(2, n, fact, inv) % mod;
        res[n] = num * binPow(24, n-2) % mod;
        int spc = (binPow(2, n) - 2 - (n - 1)) % mod;
        res[n] += spc;
        res[n] %= mod;
        /*
         *for (int u = 1; u <= n-1; ++u) {
         *    res[n] += (C(u, n, fact, inv) - 1);
         *    res[n] %= mod;
         *}
         */
    }
    int ans = 1;
    for (int i = 3; i <= m; ++i)
        ans += res[i];
    printf("%d\n", ans);
    return 0;
}
