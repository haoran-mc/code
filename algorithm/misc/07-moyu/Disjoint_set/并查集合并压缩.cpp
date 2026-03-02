//合并压缩是在'并'的过程压缩路径
//额外需要rank[]数组，储存当前树的高度
//需要分组数时，同样使用isroot[]数组
#include <cstdio>
const int maxn = 1e6;
int fa[maxn];
int ranks[maxn];

int find(int x) {  // 递归写法
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

int find_recursive(int x) {  // 递推写法，谁用这个呀，肯定用递归
    int rootx = x;
    while (fa[rootx] != rootx)
        rootx = fa[rootx];
    return rootx;
}

void union_vert(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if (rootx == rooty)
        return ;
    else {
        if (ranks[rootx] > ranks[rooty])
            fa[rooty] = rootx;
        else if (ranks[rooty] > ranks[rootx])
            fa[rootx] = rooty;
        else {
            fa[rootx] = rooty;
            ranks[rooty]++;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        ranks[i] = -1;
    }
    while (m--) {
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
