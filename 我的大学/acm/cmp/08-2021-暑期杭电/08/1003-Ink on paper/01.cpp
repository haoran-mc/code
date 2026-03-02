#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxe = 2e7 + 5;
const int maxn = 5e3 + 5;
#define bug printf("<-->\n");
#define _max(a, b) (a > b ? a : b)
typedef long long ll;

struct Info {
    int x, y;
    ll z;
} edge[maxe];

bool operator <(Info a, Info b) {
    return a.z < b.z;
}

int ox[maxn], oy[maxn];
int fa[maxn];

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &ox[i], &oy[i]);

        int idx = 1;
        ll maxi = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                ll dis = (ll)(ox[i] - ox[j]) * (ll)(ox[i] - ox[j]) + (ll)(oy[i] - oy[j]) * (ll)(oy[i] - oy[j]);
                if (idx <= n || (idx > n && dis < maxi)) {
                    edge[idx].x = i, edge[idx].y = j;
                    edge[idx].z = dis;
                    maxi = _max(maxi, edge[idx].z);
                    idx++;
                }
            }

        sort(edge + 1, edge + idx + 1);

        for (int i = 1; i <= n; ++i)
            fa[i] = i;

        ll res = 0LL;
        int cnt = 0;
        for (int i = 1; i < idx; ++i) {
            int root_x = find(edge[i].x);
            int root_y = find(edge[i].y);
            if (root_x == root_y)
                continue;
            fa[root_x] = root_y;
            res = edge[i].z;
            if (++cnt == n - 1)
                break;
        }
        printf("%lld\n", res);
    }
    return 0;
}
