#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef int Status;
int n, m;
const int maxn = 1005;
const int inf  = 0x3f3f3f3f;
int g[maxn][maxn];
bool used[maxn];
bool inq[maxn];

/*图的邻接矩阵深度优先搜索函数*/
void DFS(int vertex, int depth) {
    printf("%d ", vertex);
    used[vertex] = true;
    for (int i = 0; i < n; ++i)
        if (used[i] == false && g[vertex][i] != inf)
            DFS(i, depth + 1);
}

/*图的邻接矩阵广度优先搜索函数*/
void BFS(int vertex) {
    queue<int> quu;
    quu.push(vertex);
    inq[vertex] = true;
    while (!quu.empty()) {
        int vert = quu.front();
        printf("%d ", vert);
        quu.pop();
        for (int i = 0; i < n; ++i)
            if (inq[i] == false && g[vert][i] != inf) {
                quu.push(i);
                inq[i] = true;
            }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    memset(inq, 0, sizeof(inq));
    for (int i = 0; i < n; ++i)
        g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int ver1;
        int ver2;
        int edge;
        scanf("%d", &ver1);
        scanf("%d", &ver2);
        scanf("%d", &edge);
        g[ver1][ver2] = edge;
    }

    printf("Depth First Search:   ");
    for (int i = 0; i < n; ++i)
        if (used[i] == false)
            DFS(i, 1);
    printf("\n");

    printf("Breadth First Search: ");
    for (int i = 0; i < n; ++i)
        if (inq[i] == false)
            BFS(i);
    printf("\n");
    return 0;
}
