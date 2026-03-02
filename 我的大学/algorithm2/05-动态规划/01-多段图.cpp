#include <cstdio>
#include <cstring>

const int maxn = 100;    // 最多 100 个点
const int maxv = 1000;   // 最多 1000 个边

int cost[maxv];
int g[maxv][maxv];

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++ ) {
        int vert1, vert2, edge;
        scanf("%d %d %d", &vert1, &vert2, &edge);
        g[vert1][vert2] = edge;
    }

    memset(cost, 0x3f, sizeof cost);
    cost[0] = 0;   // 源点到源点的距离为 0

    for (int i = 1; i < n; i ++ ) {
        for (int j = 0; j < i; j ++ ) {
            if (g[j][i] != 0) {   // 节点 j 能到达节点 i
                int s = cost[j] + g[j][i];   // 以节点 j 为枢纽需要的开销
                if (s < cost[i]) {   // 说明以节点 j 为枢纽花费更少
                    cost[i] = s;
                }
            }
        }
    }
    printf("%d\n", cost[n - 1]);
    return 0;
}
