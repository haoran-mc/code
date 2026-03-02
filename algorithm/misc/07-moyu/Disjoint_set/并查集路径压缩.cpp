//路径压缩是在'查'的过程压缩路径
//没有额外需要
#include <cstdio>
const int maxn = 1e6;
int fa[maxn];

//查，有返回值，为此结点的根结点
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int find_recursive(int x) {
    int rootx = x;
    while (fa[rootx] != x) {
        rootx = fa[rootx];
    }
//路径压缩
    while (fa[x] != x) {
        int ano_x = x;
        fa[x] = rootx;
        x = fa[ano_x];
    }
    return rootx;
}

//如果有返回值，根据返回值判断当前值是否在同一集合中
void union_vert(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if (rootx != rooty)
        fa[rootx] = rooty;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) 
        fa[i] = i;

    for (int i = 0; i < m; ++i) {
        char op[2];
        int a, b;
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'M')
            union_vert(a, b);
        else if (op[0] == 'Q') {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
