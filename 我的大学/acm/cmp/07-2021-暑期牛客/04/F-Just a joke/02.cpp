#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 2e2 + 5;
int n, m;
int fa[maxn];
bool isroot[maxn];
int g[maxn][maxn];
bool used[maxn]; /*DFS搜索需要标记已访问过的顶点*/
bool ha[maxn];
int cnt = 0;
#define bug printf("<-->\n");

void DFS(int vert, int depth) {
    used[vert] = true; /*将已访问过的顶点标记为已被访问*/
    for (int i = 0; i < n; ++i)
        /*邻接矩阵初始化时就需要初始化为无穷大*/
        /*所以也就是在这里判断是否是未输入的边*/
        if (used[i] == false && g[vert][i]) {
            ++cnt;
            DFS(i, depth + 1);
        }
}

bool judge(int x) {
    for (int i = 0; i < n; ++i) 
        if (g[i][x])
            return false;
    return true;
}

void init() {
    for (int i = 0; i < n; ++i) {
        fa[i] = -1;
        isroot[i] = false;
    }
}

int root(int x) {
    if (fa[x] == -1)
        return x;
    return fa[x] = root(fa[x]);
}

void union_vert(int x, int y) {
    fa[root(x)] = root(y);
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        g[ver1][ver2] = 1;
        g[ver2][ver1] = 1;
        union_vert(ver1, ver2);
    }
    bool flag = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        memset(used, 0, sizeof used);
        int theRoot = isroot[root(i)];   //找根结点
        if (ha[theRoot])   // 如果这个组织已经拿过，continue;
            continue;
        ha[theRoot] = true;  // 如果没有被拿过，那么就先标记为true
        cnt = 0;   // 这个组织的节点数
        if (judge(theRoot)) {   // 如果这个点没有相邻的点
            flag = true;
            sum += 1;
            continue;
        }

        DFS(theRoot, 0);   // 否则还要进入一次DFS判断有多少点
        if (cnt % 2)
            flag = true;
        cnt % 2 ? sum += 1 : sum += 2;
    }
    if (!flag)
        sum--;
    printf(sum % 2 ? "Alice\n" : "Bob\n");
    return 0;
}
