#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 305;
const int inf  = 0x3f3f3f3f;
int n, m;
int u, v;
int len = 10;
int g[maxn][maxn];
bool used[maxn];
vector<int> way;
int dist[maxn];
int pre[maxn];

void DFSsimplePath(int vert) {
    way.push_back(vert);
    used[vert] = true;
    if (vert == v) {
        for (auto it = way.begin(); it != way.end(); ++it)
            *it == u ? printf("Route(%d->%d): %d ", u, v, *it) : printf("%d ", *it);
        printf("\n");
        way.pop_back();
        used[vert] = false;
        return ;
    }
    for (int i = 0; i < n; ++i)
        if (used[i] == false && g[vert][i] != inf)
            DFSsimplePath(i);
    way.pop_back();
    used[vert] = false;
}

void DFSlenN(int vert) {
    way.push_back(vert);
    used[vert] = true;
    if (vert == v) {
        int dist = 0;
        for (auto it = way.begin(); it != way.end() - 1; ++it)
            dist += g[*it][*(it+1)];
        if (dist == len) {
            for (auto it = way.begin(); it != way.end(); ++it)
                *it == u ? printf("The Route(%d->%d) len %d is: %d ", u, v, len, *it) : printf("%d ", *it);
            printf("\n");
        }
        way.pop_back();
        used[vert] = false;
        return ;
    }
    for (int i = 0; i < n; ++i)
        if (used[i] == false && g[vert][i] != inf)
            DFSlenN(i);
    way.pop_back();
    used[vert] = false;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i)
        pre[i] = i;
    dist[u] = 0;
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 0; j < n; ++j)
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert])) /*特判源点*/
                vert = j;
        used[vert] = true;
        for (int j = 0; j < n; ++j)
            if (dist[vert] + g[vert][j] < dist[j]) {
                dist[j] = dist[vert] + g[vert][j];
                pre[j]  = vert;
            }
    }
}

void route(int source, int vert) {
    if (vert == source) {
        printf("%d ", source);
        return ;
    }
    route(source, pre[vert]);
    printf("%d ", vert);
}


int main() {
    scanf("%d %d", &n, &m); /*n:顶点个数; m:边的个数*/
    scanf("%d %d", &u, &v); /*从顶点u到顶点v的所有最短路径*/
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    /*求简单路径*/
    DFSsimplePath(u);

    /*求长度为len的路径*/
    memset(used, 0, sizeof(used));
    way.clear();
    DFSlenN(u);

    /*求最短路径*/
    dijkstra();
    printf("The shortest route from %d to %d: ", u, v);
    route(u, v);
    printf("\n");
    return 0;
}
