#define bug printf("<-->\n");
#define lowbit(x) ((x) & -(x)) //lowbit(ob0010) = 2
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define NEXTLINE puts("");
#include <cstdio>
const int maxn = 5000 + 5;
int g[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n, r;
    scanf("%d %d", &n, &r);
    int row = r, col = r;
    for (int i = 0, x, y, w; i < n; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        ++x, ++y;  //可以不处理边界问题
        row = _max(row, x), col = _max(col, y);
        g[x][y] += w;
    }

    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];

    int res = 0;
    for (int i = r; i <= row; ++i)
        for (int j = r; j <= col; ++j)
            res = _max(res, g[i][j] - g[i-r][j] - g[i][j-r] + g[i-r][j-r]);

    printf("%d\n", res);
    return 0;
}
