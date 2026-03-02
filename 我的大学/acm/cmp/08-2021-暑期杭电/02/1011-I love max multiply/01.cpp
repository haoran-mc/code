#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
const int maxn = (1 << 19) + 5;
#define NEXTLINE puts("");
typedef long long ll;
ll A[maxn], B[maxn], C[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &A[i]);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &B[i]);

        for (int i = n-1; i >= 0; --i)
            for (int j = n-1; j >= 0; --j)
                for (int k = 0; k <= (i & j); ++k)
                    C[k] = max(C[k], A[i] * B[j]);

        ll res = 0;
        for (int i = 0; i < n; ++i)
            printf("%d ", C[i]);
        NEXTLINE;
        for (int i = 0; i < n; ++i) {
            res += C[i];
            res %= mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}
