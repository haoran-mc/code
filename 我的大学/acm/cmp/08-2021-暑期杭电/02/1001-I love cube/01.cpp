#include <cstdio>
typedef long long ll;
const ll mod = 1e9 + 7;

ll binPow(ll base, ll expo, ll mod) {
    ll res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1ll * res * base) % mod;

        base = (1ll * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binPow(x, mod-2, mod);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        // ll res1 = (n % mod) * (n % mod) * ((n - 1) % mod) * ((n - 1) % mod) * (inv(4LL) % mod) * 8;
        ll res2 = (n % mod) * (n % mod) % mod * ((n - 1) % mod) % mod * ((n - 1) % mod) % mod * 2 % mod;
        // printf("%lld\n", res1 % mod);
        printf("%lld\n", res2 % mod);
    }
    return 0;
}
