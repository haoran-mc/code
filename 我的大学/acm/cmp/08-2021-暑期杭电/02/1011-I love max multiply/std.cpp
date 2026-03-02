#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = (1 << 20) + 5;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll res[maxn];
int A[maxn], B[maxn], a[maxn], b[maxn];

int main() {
    int t; scanf("%d", &t);
    while(t--)  {
        int n; scanf("%d",&n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            A[i] = a[i];
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
            B[i] = b[i];
        }
        int m = 1;
        while (m < n) 
            m <<= 1;
        for (int i = n; i < m; ++i) {
            A[i] = B[i] = -INF;
            a[i] = b[i] = INF;
        }
        for (int j = 1; j < m; j <<= 1)
            for (int i = m-1; i >= 0; --i)
                if (!(i & j)) {
                    A[i] = max(A[i], A[i^j]);
                    B[i] = max(B[i], B[i^j]);
                    a[i] = min(a[i], a[i^j]);
                    b[i] = min(b[i], b[i^j]);
                }

        res[n] = -LLINF;
        for (int i = n-1; i >= 0; --i) {
            res[i] = -LLINF;
            if (A[i] != -INF && B[i] != -INF)
                res[i] = max(res[i], (ll)A[i] * (ll)B[i]);

            if (A[i] != -INF && b[i] != INF)
                res[i] = max(res[i], (ll)A[i] * (ll)b[i]);

            if (a[i] != INF && B[i] != -INF)
                res[i] = max(res[i], (ll)a[i] * (ll)B[i]);

            if (a[i] != INF && b[i] != INF)
                res[i] = max(res[i], (ll)a[i] * (ll)b[i]);

            res[i]=max(res[i],res[i+1]);
        }
        ll C = 0;
        for(int i = 0; i < n; ++i) {
            C += (res[i] % MOD);
            C %= MOD;
        }
        C = (C % MOD + MOD) % MOD;
        printf("%lld\n", C);
    }
    return 0;
}
