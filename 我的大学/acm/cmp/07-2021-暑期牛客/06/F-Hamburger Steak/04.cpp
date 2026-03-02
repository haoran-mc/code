#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
ll t[maxn], a[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ll maxi = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        sum += t[i];
        maxi = max(maxi, t[i]);
    }
    // 制作最短需要的时间
    ll T = max(maxi, (sum+m-1) / m);

    int p = 1;
    for (int i = 1; i <= n; i++) {
        while (a[p] >= T)
            p++;

        if (a[p] + t[i] <= T) {
            // 只需要在一个锅中制作
            // 1 id l r
            printf("1 %lld %lld ", p, a[p]);
            a[p] += t[i];
            printf("%d\n", a[p]);

            if (a[p] == T)
                p ++;
            continue;
        }

        // 在两个锅中制作
        // 2 id l r id l r
        printf("2 %lld 0 %lld %lld %lld %lld\n", p + 1, t[i] - (T - a[p]), p, a[p], T);

        p ++;
        a[p] = t[i] - (T - a[p-1]);
        a[p-1] = T;
    }
    return 0;
}
