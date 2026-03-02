#include <cstdio>
typedef long long ll;
ll cnt = 0;

ll solve(ll n, ll k) {
    if (n <= k)
        return 1;
    if (k == 1)
        return 2 * n - 1;
    ll cnt = 0;
    ll tt = 2;
    for (ll b = k, i = 1; ; ) {
        if (b + k + (tt / 2 - 1) * (k - 1) >= n) {
            ++ cnt;
            break;
        }
        else {
            ++ cnt;
            b += k + (tt / 2 - 1) * (k - 1);
            ++ i;
            if (b + tt - 1 >= n) {
                cnt += n - b;
                break;
            }
            else {
                b += tt - 1;
                cnt += tt - 1;
                tt *= 2;
            }
        }
    }
    return 2 * cnt + 1;
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        if (k == 1)
            printf("%lld\n", 2 * n - 1);
        else
            printf("%lld\n", solve(n, k));
    }
    return 0;
}
