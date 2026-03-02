#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
map<ll, ll> mp;
ll a[maxn], cnt;

int main() {
    ll n; scanf("%lld", &n);
    ll t;
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &t);
        if (mp.find(t) == mp.end())
            a[cnt++] = t;
        ++mp[t];
    }
    sort(a, a + cnt);
    ll res = 0;
    for (ll i = 0; i < cnt; ++i) {
        if (mp.find(a[i] * a[i]) != mp.end())
            res += mp[a[i]] * mp[a[i]] * mp[a[i] * a[i]];
        for (ll j = i + 1; j < cnt && a[i] * a[j] <= a[cnt - 1]; ++j) {
            ll tmp = a[i] * a[j];
            if (mp.find(tmp) != mp.end())
                res += 2 * mp[a[i]] * mp[a[j]] * mp[tmp];
        }
    }
    printf("%lld\n", res);
    return 0;
}
