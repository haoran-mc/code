#include <cstdio>
const int MOD = 4933;
typedef long long ll;

ll binPow(ll base, ll expo, ll MOD) {
    ll res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1ll * res * base) % MOD;

        base = (1ll * base * base) % MOD;
        expo >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binPow(x, MOD-2, MOD);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, m, k, a, l;
    scanf("%d %d %d %d %d", &n, &m, &k, &a, &l);
    ll d1 = 1, d2 = 1;
    for (int i = 0; i < k; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        d1 *= (ll)(z - y), d2 *= (ll)z;
    }
    d1 += d2;
    d1 *= inv(d2);
    printf("%lld\n", d1 % MOD);
    return 0;
}
