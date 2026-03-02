#include <cstdio>
#include <algorithm>
using std::max;
const int maxn = 1e5 + 5;
int h[maxn], l[maxn], r[maxn];
long long preS[maxn];
long long res;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        preS[i] = preS[i - 1] + h[i];
        l[i] = r[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        while (h[l[i] - 1] >= h[i])
            l[i] = l[l[i] - 1];

    for (int i = n; i >= 1; --i)
        while (h[r[i] + 1] >= h[i])
            r[i] = r[r[i] + 1];

    for (int i = 1; i <= n; ++i) 
        res = max(res, h[i] * (preS[r[i]] - preS[l[i] - 1]));
    printf("%lld\n", res);
    return 0;
}
