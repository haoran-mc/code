#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 0x7fffffff;
const int N = 100 + 10;
int map[N][N];
int dist[N];
int n;
void prime() {
    int min_edge, min_node;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    int ans = 0;
    int now = 1;
    for (int i = 1; i < n; i++) {
        dist[now] = -1;
        min_edge = INF;
        for (int j = 1; j <= n; j++) {
            if (j != now&& dist[j] >= 0) {
                if (map[now][j] >= 0)
                    dist[j] = min(dist[j], map[now][j]);
                if (dist[j] < min_edge) {
                    min_edge = dist[j];
                    min_node = j;
                }
            }
        }
        ans += min_edge;
        now = min_node;
    }
    printf("%d", ans);
}

int main() {
    scanf("%d", &n) ;
        memset(map, 0, sizeof(map));
        int a, b, d, s;
        for (int i = 0; i < n*(n - 1) / 2; i++) {
            scanf("%d%d%d%d", &a, &b, &d, &s);
            if (s == 0)
                map[a][b] = map[b][a] = d;
            else if (s == 1) map[a][b] = map[b][a] = 0;
        }
        prime();
    return 0;
}
