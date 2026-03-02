#include <cstdio>
#include <cstring>
const int maxn = 505;
int n, m;
bool g[maxn][maxn];
bool flag;
int res;
int orin;
int goal;
int dist[maxn];

void DFS(int node) {
    if (node == goal) {
        ++res;
        return ;
    }
    bool runby = false;
    for (int i = 1; i <= n; ++i)
        if (g[node][i]) {
            runby = true;
            DFS(i);
        }
    if (!runby)
        flag = true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= m; ++i) {
        int ver1;
        int ver2;
        scanf("%d %d", &ver1, &ver2);
        g[ver1][ver2] = true;
    }
    scanf("%d %d", &orin, &goal);
    for (int i = 1; i <= n && !flag; ++i)
        if (g[goal][i])
            flag = true;
    DFS(orin);
    printf("%d ", res);
    flag ? printf("No\n") : printf("Yes\n");
    return 0;
}
