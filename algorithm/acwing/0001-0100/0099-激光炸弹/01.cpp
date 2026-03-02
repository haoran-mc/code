#define bug printf("<-->\n");
#define lowbit(x) ((x) & -(x)) //lowbit(ob0010) = 2
#define _max(a, b) (a > b ? a : b)
#define _min(a, b) (a < b ? a : b)
#define NEXTLINE puts("");
#include <cstdio>
const int maxn = 5000 + 5;
int preS[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int n, r;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        preS[x][y] += w;
    }
    for (int i = 1; i < maxn; ++i)
        preS[i][0] = preS[i-1][0] + preS[i][0];
    for (int j = 1; j < maxn; ++j)
        preS[0][j] = preS[0][j-1] + preS[0][j];

    for (int i = 1; i < maxn; ++i)
        for (int j = 1; j <= i; ++j)
            preS[i][j] = preS[i-1][j] + preS[i][j-1] - preS[i-1][j-1] + preS[i][j];

    int res = 0;
    for (int i = r-1; i < maxn; ++i)
        for (int j = r-1; j < maxn; ++j) {
            if (i >= r && j >= r)
                res = _max(res, preS[i][j] - preS[i-r][j] - preS[i][j-r] + preS[i-r][j-r]);
            else if (i >= r && j < r)
                res = _max(res, preS[i][j] - preS[i-r][j]);
            else if (i < r && j >= r)
                res = _max(res, preS[i][j] - preS[i][j-r]);
            else
                res = _max(res, preS[i][j]);
    }
    printf("%d\n", res);
    return 0;
}
