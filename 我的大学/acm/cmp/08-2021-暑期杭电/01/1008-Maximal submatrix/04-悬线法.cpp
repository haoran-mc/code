#include <cstdio>
#include <algorithm>
#include <cstring>
using std::max;
const int maxn = 2e3 + 5;
int h[maxn][maxn];
int pos[maxn][maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int res = 0;
        memset(pos, 0, sizeof pos);
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%d", &h[i][j]);

                if (i && h[i][j] >= h[i-1][j])
                    pos[i][j] = pos[i-1][j] + 1;
                else
                    pos[i][j] = 1;
            }

        for (int i = 0; i < n; ++i) {
            int l[maxn], r[maxn];
            for (int j = 0; j < m; ++j)
                l[j] = r[j] = j;

            for (int j = 0; j < m; j++)
                while (l[j] != 0 && pos[i][l[j] - 1] >= pos[i][j])
                    l[j] = l[l[j] - 1];

            for (int j = m-1; j >= 0; j--)
                while (r[j] != m-1 && pos[i][r[j] + 1] >= pos[i][j])
                    r[j] = r[r[j] + 1];

            for (int j = 0; j < m; j++)
                res = max(res, (r[j] - l[j] + 1) * pos[i][j]);
        }
        printf("%d\n", res);
    }
    return 0;
}
