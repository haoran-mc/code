/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月08日 星期日 20时09分43秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int fa[maxn];
int size[maxn];

int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        size[i] = 1;
    }
    while (m--) {
        char op[5]; scanf("%s", op);
        if (op[0] == 'C') {
            int a, b;
            scanf("%d %d", &a, &b);
            if (find(a) == find(b))
                continue;
            size[find(b)] += size[find(a)];
            fa[find(a)] = find(b);
        }
        else if (op[1] == '1') {
            int a, b;
            scanf("%d %d", &a, &b);
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
        else if (op[1] == '2') {
            int a; scanf("%d", &a);
            printf("%d\n", size[find(a)]);
        }
    }
    return 0;
}
