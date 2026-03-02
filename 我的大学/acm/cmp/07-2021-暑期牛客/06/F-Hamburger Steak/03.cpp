#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
ll t[maxn], a[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    ll S = 0;
    ll tmax = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        S += t[i];
        tmax = max(tmax, t[i]);
    }
    ll T = max(tmax, (S+m-1) / m);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        while (a[p] >= T)
            p++;

        if (a[p] + t[i] <= T) {
            printf("1 %d %d ", p, a[p]);
            a[p] += t[i];
            printf("%d\n", a[p]);

            if (a[p] == T)
                p ++;
            continue;
        }

        // 分两半
        printf("2 %d 0 %d %d %d %d\n", p + 1, t[i] - (T - a[p]), p, a[p], T);

        p++;
        a[p] = t[i] - (T-a[p-1]);
        a[p-1] = T;
    }
    return 0;
}
