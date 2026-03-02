#include <cstdio>
const int maxn = 1e5 + 5;
int a[maxn];
int fa[maxn];

// 返回x的祖宗结点 + 路径压缩
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;

        int flag = true;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (i != 1 && a[i] != a[i-1])
                flag = false;
        }
        if (flag) {
            printf("YES\n");
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            // 如果还没到最后一个数就出现环
            if (i != n && find(i) == find(a[i])) {
                printf("NO\n");
                break;
            }
            // 如果最后一个出现环
            if (i == n && find(i) == find(a[i])) {
                printf("YES\n");
                break;
            }
            // 如果最后一个没有出现环
            if (i == n && find(i) != find(a[i])) {
                printf("NO\n");
                break;
            }
            fa[find(i)] = a[i];
        }
    }
    return 0;
}
