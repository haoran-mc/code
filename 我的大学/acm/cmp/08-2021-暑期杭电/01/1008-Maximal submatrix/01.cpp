#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define NEXTLINE puts("");

const int maxn = 2e3 + 5;
int g[maxn][maxn];

struct subMatrix {
    int lrow, lcol;
    int urow, ucol;
} dp[2][maxn];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t; scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));

        int n, m;
        scanf("%d %d", &n, &m);

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &g[i][j]);
                if (i == 1) {
                    dp[i%2][j].lrow = 1, dp[i%2][j].lcol = 1;
                    dp[i%2][j].urow = 1, dp[i%2][j].ucol = 1;
                    res = max(res, dp[i%2][j].lrow * dp[i%2][j].lcol);
                    res = max(res, dp[i%2][j].urow * dp[i%2][j].ucol);
                    continue;
                }
                if (g[i][j] >= g[i-1][j]) {
                    dp[i%2][j].lrow = max(dp[i%2][j-1].lrow, 1);
                    dp[i%2][j].lcol = dp[i%2][j-1].lcol + 1;
                    dp[i%2][j].urow = dp[(i-1)%2][j].urow + 1;
                    dp[i%2][j].ucol = max(dp[(i-1)%2][j].ucol, 1);
                } else {
                    dp[i%2][j].lrow = 1;
                    dp[i%2][j].lcol = 1;
                    dp[i%2][j].urow = 1;
                    dp[i%2][j].ucol = 1;
                }
                res = max(res, dp[i%2][j].lrow * dp[i%2][j].lcol);
                res = max(res, dp[i%2][j].urow * dp[i%2][j].ucol);
            }
            for (int j = 1; j <= m; ++j) {
                printf("%d %d %d %d     ", dp[i%2][j].lrow, dp[i%2][j].lcol, dp[i%2][j].urow, dp[i%2][j].ucol);
            }
            NEXTLINE 
        }
        /*
         * for (int i = 1; i <= n; ++i) {
         *     for (int j = 1; j <= m; ++j)
         *         printf("%d %d %d %d     ", dp[i%2][j].lrow, dp[i%2][j].lcol, dp[i%2][j].urow, dp[i%2][j].ucol);
         *     NEXTLINE
         * }
         */

        printf("%d\n", max(res, m));
    }
    return 0;
}
