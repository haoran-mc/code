#include <cstdio>
typedef long long ll;
ll cnt[105];

ll get(ll i) {
  if (i < 100)
    return cnt[i];
  else
    return cnt[99] + (i - 99);
}

int main() {
    int t; scanf("%d", &t);
    ll l, r;
    for (int i = 1; i < 100; ++i) {
        if (i < 10) {
            cnt[i] = cnt[i - 1];
            if (i % 3 == 0)
                ++cnt[i];
        }
        else {
            cnt[i] = cnt[i - 1];
            int a = i % 10;
            int b = i / 10;
            if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0 || i % 3 == 0)
                ++cnt[i];
        }
    }
    // cout << cnt[99] << '\n';
    while (t--) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", get(r) - get(l - 1));
    }
    return 0;
}

