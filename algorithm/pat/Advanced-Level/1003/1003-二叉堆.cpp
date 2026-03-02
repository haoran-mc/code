#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1005; /*顶点数的最大值*/
const int M = 1005; /*边数的最大值*/
#define bug printf("<------>\n");
int n, m;
int source;
int save;
int tot;
int head[N];
int vert[M];
int edge[M];
int nxet[M];
int dist[N];
bool used[N];
int route[N];
int teams[N];
int gather[N];
priority_queue<pair<int, int>> pqu;

void add(int x, int y, int z) {
    vert[++tot] = y;
    edge[tot] = z;
    nxet[tot] = head[x];
    head[x] = tot;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    memset(route, 0, sizeof(route));
    dist[source] = 0;
    route[source] = 1;
    pqu.push(make_pair(0, source));
    while (pqu.size()) {
        int x = pqu.top().second;
        pqu.pop();
        if (used[x])
            continue;
        used[x] = true;
        for (int i = head[x]; i; i = nxet[i]) {
            int y = vert[i];
            int z = edge[i];
            if (dist[y] > dist[x] + z) {
                dist[y] = dist[x] + z;
                gather[y] = gather[x] + teams[y];
                route[y] = route[x];
                pqu.push(make_pair(-dist[y], y));
            }
            else if (dist[y] == dist[x] + z) {
                route[y] += route[x];
                if (gather[y] < gather[x] + teams[y])
                    gather[y] = gather[x] + teams[y];
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &source);
    scanf("%d", &save);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &teams[i]);
        gather[i] = teams[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        add(y, x, z);
        add(x, y, z);
    }
    dijkstra();
    printf("%d %d\n", route[save], gather[save]);
    return 0;
}
