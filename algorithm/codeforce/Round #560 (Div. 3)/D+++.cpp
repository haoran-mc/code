#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 305;
LL divi[maxn];
LL fact[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &divi[i]);
        sort(divi, divi+n);
        LL x = divi[0] * divi[n-1];
    }
    return 0;
}
