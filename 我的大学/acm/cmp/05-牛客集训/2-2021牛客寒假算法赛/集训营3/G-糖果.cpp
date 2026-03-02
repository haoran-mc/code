#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
int n, m;
const int maxn = 1e6 + 5;
//vector<int> suger;
int suger[maxn];
int fa[maxn];

int root2(int x) {
    int x_root = x;
    while (fa[x_root] != -1) {
        x_root = fa[x_root];
    }
    while (fa[x] != -1) {
        int anox = x;
        x = fa[x];
        fa[anox] = x_root;
    }
    return x_root;
}

int root3(int x) {
    int x_root = x;
    while (fa[x_root] != -1) {
        x_root = fa[x_root];
    }
    return x_root;
}

int root(int x) {
    if (fa[x] == -1)
        return x;
    return fa[x] = root(fa[x]);
}

void union_vert(int x, int y) {
    int root_x = root2(x);
    int root_y = root2(y);
    if (suger[root_x] < suger[root_y])
        fa[root_x] = root_y;
    else
        fa[root_y] = root_x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &suger[i]);
    }
    for (int i = 1; i <= n; ++i)
        fa[i] = -1;
    for (int i = 1; i <= m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        union_vert(ver1, ver2);
    }
    LL purchase = 0;
    for (int i = 1; i <= n; ++i) {
        if (fa[i] == -1)
            purchase += suger[i];
        else
            purchase += suger[root3(i)];
    }
    printf("%lld\n", purchase);
    return 0;
}
