#include <cstdio>
#include <cstring>
typedef long long ll;
const int maxn = 1e5 + 5;
const int MOD =  998244353;
int preS[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        char str[maxn];
        scanf("%s", str + 1);
        ll res = 0;
        for (int c = 'a'; c <= 'z'; ++c) {
            for (int i = 1; i <= strlen(str+1); ++i)
                preS[i] = (int)str[i] == c ? preS[i-1] + 1 : preS[i-1];

            for (int i = 1; i <= strlen(str+1); ++i)
                for (int j = i; j <= strlen(str+1); ++j)
                    res = res % MOD + (ll)(preS[j] - preS[i-1]) * (ll)(preS[j] - preS[i-1]) % MOD;
        }
        printf("%lld\n", res % MOD);
    }
    return 0;
}
