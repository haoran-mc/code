#include <cstdio>
const int maxn = 1e5 + 5;
int son[maxn][26], cnt[maxn], idx;   // 下标是0的点，既是根结点，又是空节点

void insert(char str[]) {
    int p = 0;   // 根结点
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) 
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;   // 画个星星标记
}

// 查询这个字符串出现次数
int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        char op[2];
        char str[maxn];
        scanf("%s %s", op, str);
        if (op[0] == 'I')
            insert(str);
        else if (op[0] == 'Q')
            printf("%d\n", query(str));
    }
    return 0;
}
