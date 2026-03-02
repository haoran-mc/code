#include <cstdio>
#include <algorithm>
const int maxn = 1e3 + 5;
using std::max;
#define NEXTLINE puts("");
int h[maxn];
int l[maxn], r[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    int res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch = ' ';
            while (ch == ' ' || ch == '\n')
                scanf("%c", &ch);

            ch == 'F' ? h[j]++ : h[j] = 0;

            l[j] = r[j] = j;
        }

        for (int j = 1; j <= m; j++)
            while (l[j] != 1 && h[l[j] - 1] >= h[j])
                l[j] = l[l[j] - 1];

        for (int j = m; j >= 1; j--)
            while (r[j] != m && h[r[j] + 1] >= h[j])
                r[j] = r[r[j] + 1];

        for (int j = 1; j <= m; j++)
            res = max(res, (r[j] - l[j] + 1) * h[j]);
    }
    printf("%d", res * 3);
    return 0;
}
