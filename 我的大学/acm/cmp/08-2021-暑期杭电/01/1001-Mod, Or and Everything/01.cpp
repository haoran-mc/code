#include <cstdio>
#include <cmath>
#define lowbit(x) ((x) & -(x)) //lowbit(ob0100) = 4
#define bug printf("<-->\n");
typedef long long ll;

ll judge(ll n) {
    ll res;
    while (n) {
        res = lowbit(n);
        n -= res;
    }
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll t; scanf("%lld", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        // 1. 判断 2^k < n <= 2^{k+1}
        // 2. 输出 2^{k+1}
        ll res = judge(n-1) - 1;
        printf("%lld\n", res);
    }
    return 0;
}
