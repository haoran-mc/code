#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 505;
#define bug printf("<------>\n");
int n, m;
int source;
int save;
int g[maxn][maxn];
int dist[maxn];
bool used[maxn];
int teams[maxn];
int route[maxn]; /*到顶点i的路径有几条*/
int gather[maxn]; /*到顶点i的路径中能集合的队伍最大数*/

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    memset(route, 0, sizeof(route));
    dist[source] = 0;
    route[source] = 1;
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 0; j < n; ++j)
            if (used[j] == false && (vert == -1 || dist[j] < dist[vert]))
                vert = j;
        used[vert] = true;
        for (int j = 0; j < n; ++j) { /*搜索所有vert能够到达的顶点，更新路径最短距离*/
            if (dist[j] > dist[vert] + g[vert][j]) { /*遇到更短路*/
                dist[j] = dist[vert] + g[vert][j];
                gather[j] = gather[vert] + teams[j];
                route[j] = route[vert];
            }
            else if (dist[j] == dist[vert] + g[vert][j] && j != vert) { /*遇到同样长的路*/
                route[j] += route[vert];
                if (gather[j] < gather[vert] + teams[j])
                    gather[j] = gather[vert] + teams[j];
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
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int city1;
        int city2;
        int dist;
        scanf("%d", &city1);
        scanf("%d", &city2);
        scanf("%d", &dist);
        g[city1][city2] = min(g[city1][city2], dist);
        g[city2][city1] = min(g[city2][city1], dist);
    }
    dijkstra();
    printf("%d %d\n", route[save], gather[save]);
    return 0;
}
