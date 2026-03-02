#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e3 + 5;
typedef long long ll;
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define bug printf("<-->\n");
int ox[maxn], oy[maxn];
ll g[maxn][maxn];
ll dist[maxn];
bool used[maxn];
int source;   // 从1号节点开始的最小生成树

void prim(int n) {
    memset(dist, 0x3f3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    dist[source] = 0;
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 0; j < n; ++j)
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert]))
                vert = j; /*筛选出未在集合中的距离集合最近的顶点，*/
        used[vert] = true; /*将vert加到集合中*/
        for (int j = 0; j < n; ++j)
            if (used[j] == false) 
                dist[j] = _min(dist[j], g[vert][j]); /*更新顶点距离*/
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &ox[i], &oy[i]);
        memset(g, 0x3f3f, sizeof(g));
        for (int i = 0; i < n; ++i)
            g[i][i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                ll dis = (ll)(ox[i] - ox[j]) * (ll)(ox[i] - ox[j]) + (ll)(oy[i] - oy[j]) * (ll)(oy[i] - oy[j]);
                g[i][j] = dis;
                g[j][i] = dis;
            }
        prim(n);
        ll res = 0;
        for (int i = 0; i < n; ++i) 
            res = _max(res, dist[i]);
        printf("%lld\n", res);
    }
    return 0;
}
