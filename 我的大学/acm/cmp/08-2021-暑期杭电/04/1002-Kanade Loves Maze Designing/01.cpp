#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 2e3 + 5;
int ve[maxn], ne[maxn], h[maxn], tot;
int c[maxn], hac[maxn];
bool used[maxn];
int source = 1, a[maxn][maxn];
#define NEXTLINE puts("");
#define bug printf("<-->\n");

//加入有向边(x, y)，权值为z
void add(int x, int y) {
    ve[tot] = y;
    ne[tot] = h[x];
    h[x] = tot++;
}

void DFS(int e, int pre) {
    used[e] = true;
    if (hac[c[e]])
        a[source][e] = a[source][pre];
    else
        a[source][e] = a[source][pre] + 1;

    hac[c[e]]++;
    for (int i = h[e]; i; i = ne[i])
        if (!used[i]) {
            printf("%d\n", i);
            int y = ve[i];
            DFS(y, i);
        }
    // used[e] = false;
    hac[c[e]]--;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        memset(used, 0, sizeof used);
        int n; scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            int ve1; scanf("%d", &ve1);
            int ve2 = i;
            add(ve1, ve2);
            add(ve2, ve1);
        }
        for (int i = 1; i <= n; ++i) 
            scanf("%d", &c[i]);
        memset(used, 0, sizeof used);
        DFS(source, 1);
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) 
                printf("%d ", a[i][j]);
            NEXTLINE;
        }
    }
    return 0;
}
