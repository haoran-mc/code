#include <cstdio>
#include <cstring>
const int maxn = 1e6 + 5;
int ha[maxn];
int a[maxn];

int main() {
    int len, t; scanf("%d %d", &len, &t);
    memset(a, 0, sizeof(a));
    bool flag = false;
    while (t --) {
        int p, x;
        scanf("%d %d", &p, &x);
        if (p < x)   // 竟然出现a[p]前面有a个比它大的数，输出-1
            flag = true;
        if (p == x)  // 显然，前面都是顺序排列
            for (int i = 1; i <= p; ++i) {
                a[i] = i;
                ha[i] = 1;
            }
        if (p > x) {  // 这个位置是x
            a[p] = x;
            ha[x] = 1;
        }
    }
    if (flag) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= len; ++i) {
        if (a[i])
            continue;
        for (int j = 1; j <= len; ++j)
            if (!ha[j]) {
                ha[j] = 1;
                a[i] = j;
                break;
            }
    }
    for (int i = 1; i <= len; ++i)
        printf("%d ", a[i]);
    return 0;
}
