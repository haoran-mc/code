#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1005;
vector<int> g[maxn];
bool used[maxn];
bool inq[maxn];

void DFS(int vertex, int depth) {
    printf("%d ", vertex);
    used[vertex] = true;
    for (int i = 0; i < (int)g[vertex].size(); ++i) {
        int vert = g[vertex][i];
        if (used[vert] == false)
            DFS(vert, depth);
    }
}

void BFS(int vertex) {
    queue<int> quu;
    quu.push(vertex);
    inq[vertex] = true;
    while (!quu.empty()) {
        int vert = quu.front();
        printf("%d ", vert);
        quu.pop();
        for (int i = 0; i < (int)g[vert].size(); ++i) {
            int v = g[vert][i];
            if (inq[v] == false) {
                quu.push(v);
                inq[v] = true;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int ver1;
        int ver2;
        int edge;
        scanf("%d", &ver1);
        scanf("%d", &ver2);
        scanf("%d", &edge);
        g[ver1].push_back(edge);
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
