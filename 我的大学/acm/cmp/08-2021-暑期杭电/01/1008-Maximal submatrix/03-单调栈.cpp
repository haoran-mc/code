#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
#define NEXTLINE puts("");
#define bug printf("<-->\n");
const int maxn = 2e3 + 5;
int h[maxn][maxn];
int pos[maxn][maxn];
int stk[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        int res = 0;
        memset(pos, 0, sizeof pos);
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &h[i][j]);

                if (i && h[i][j] >= h[i-1][j])
                    pos[i][j] = pos[i-1][j] + 1;
                else
                    pos[i][j] = 1;
            }
            pos[i][m] = 0;
        }
        /*
         * for (int i = 0; i < n; ++i) {
         *     for (int j = 0; j <= m; ++j)
         *         printf("%d ", pos[i][j]);
         *     NEXTLINE;
         * }
         */

        for (int i = 0; i < n; ++i) {
            int tt = 0;
            int width[maxn];
            for (int j = 0; j <= m; ++j) {
                if (pos[i][j] >= stk[tt]) {
                    stk[++tt] = pos[i][j];
                    width[tt] = 1;
                }
                else {
                    int cnt = 0;
                    while (tt && stk[tt] > pos[i][j]) {
                        cnt += width[tt];
                        res = max(res, cnt * stk[tt]);
                        tt--;
                    }
                    stk[++tt] = pos[i][j];
                    width[tt] = cnt + 1;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
