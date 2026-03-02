#include <cstdio>
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        // ll mini = ((n % mod) * (((((n % mod) + 1) % mod) * (((n % mod) + 1) % mod)) % mod) % mod) * (((((((n % mod) * (n % mod) % mod) * (n % mod)) % mod + ((((n % mod) * (n % mod)) % mod) * (7 % mod)) % mod) % mod + ((n % mod) * (2 % mod) % mod) - 4) % mod) % mod) % mod;
        ll e1 = (n % mod);
        ll e2 = ((((n % mod) + 1) % mod) * (((n % mod) + 1) % mod) % mod);
        ll e3 = ((((((n % mod) * (n % mod) % mod) * (n % mod) % mod) + (((n % mod) * (n % mod) % mod) * (7 % mod) % mod)) % mod + ((n % mod) * (2 % mod) % mod) - 4) % mod);
        ll mini = e1 * e2 % mod * (e3 % mod) % mod / 24;

        // ll maxi = (((((n % mod) * (n % mod)) % mod * (n % mod)) % mod * (n % mod)) % mod * ((((n + 1) % mod) * ((n + 1 ) % mod)) % mod) % mod) * ((n % mod * 2 % mod + 1) % mod) % mod;
        ll f1 = (((((n % mod) * (n % mod)) % mod) * (n % mod) % mod) * (n % mod) % mod);
        ll f2 = (((n % mod + 1) % mod) * ((n % mod + 1) % mod) % mod);
        ll f3 = ((n % mod * 2 % mod + 1) % mod);
        ll maxi = f1 * f2 % mod * (f3 % mod) % mod / 12;
        printf("%lld\n%lld", mini % mod, maxi % mod);
    }
    return 0;
}
