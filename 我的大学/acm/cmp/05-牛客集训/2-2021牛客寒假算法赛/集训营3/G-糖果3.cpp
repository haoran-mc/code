#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
int n, m;
const int maxn = 1e6 + 5;
//vector<int> suger;
int suger[maxn];
int fa[maxn];
bool isroot[maxn];
int ranks[maxn];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = -1;
        isroot[i] = false;
        ranks[i] = -1;
    }
}

int root(int x) {
    int x_root = x;
    while (fa[x_root] != -1) {
        x_root = fa[x_root];
    }
    return x_root;
}

/*
 *int root(int x) {
 *    if (fa[x] == -1)
 *        return x;
 *    else {
 *        int x_root = root(fa[x]);
 *        return x_root;
 *    }
 *}
 */

void union_vert(int x, int y) {
    int x_root = root(x);
    int y_root = root(y);

    if (x_root == y_root)
        return ;
    else {
        if (ranks[x_root] > ranks[y_root]) {
            if (suger[x_root] < suger[y_root])
                suger[x_root] = suger[y_root];
            fa[y_root] = x_root;
        }
        else if (ranks[y_root] > ranks[x_root]) {
            if (suger[y_root] < suger[x_root])
                suger[y_root] = suger[x_root];
            fa[x_root] = y_root;
        }
        else {
            if (suger[x_root] > suger[y_root]) {
                fa[y_root] = x_root;
                ranks[x_root]++;
            }
            else if (suger[y_root] > suger[x_root]) {
                fa[x_root] = y_root;
                ranks[y_root]++;
            }
            else {
                fa[x_root] = y_root;
                ranks[y_root]++;
            }
        }
    }
}

//int root2(int x) {
    //int x_root = x;
    //while (fa[x_root] != -1) {
        //x_root = fa[x_root];
    //}
    //while (fa[x] != -1) {
        //int anox = x;
        //x = fa[x];
        //fa[anox] = x_root;
    //}
    //return x_root;
//}

//int root3(int x) {
    //int x_root = x;
    //while (fa[x_root] != -1) {
        //x_root = fa[x_root];
    //}
    //return x_root;
//}

//int root(int x) {
    //if (fa[x] == -1)
        //return x;
    //return fa[x] = root(fa[x]);
//}

//void union_vert(int x, int y) {
    //int root_x = root2(x);
    //int root_y = root2(y);
    //if (suger[root_x] < suger[root_y])
        //fa[root_x] = root_y;
    //else
        //fa[root_y] = root_x;
//}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &suger[i]);
    }
    init(n);
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
            purchase += suger[root(i)];
    }
    //for (int i = 0; i < n; ++i)
        //printf("fa = %d\n", fa[i]);
    printf("%lld\n", purchase);
    return 0;
}
