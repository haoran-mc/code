#include <cstdio>
#include <algorithm>
using std::max;
const int maxn = 5e3;
int a[maxn][maxn], b[maxn][maxn];
int h[maxn];
int que[maxn];

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++){
                scanf("%d", &a[i][j]);
                b[i][j] = 0;
                if (i > 1)
                    b[i][j] = (a[i][j] >= a[i-1][j]);
            }
        }
        for (int i = 1; i <= m; i++)
            h[i]=0;

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (b[i][j] == 0)
                    h[j] = 1;
                else
                    h[j]++;
            }
            int tot = 0;
            h[m+1] = 0;
            for (int j = 1; j <= m+1; j++) {
                while (tot && h[que[tot]] > h[j]) {
                    res = max(res, (j-que[tot-1]-1) * h[que[tot]]);
                    tot--;
                }
                que[++tot] = j;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
