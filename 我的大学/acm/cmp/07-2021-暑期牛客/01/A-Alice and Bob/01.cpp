#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e3 + 5;
int ha[maxn];
int res[maxn][maxn];

int main() {
    int t; scanf("%d", &t);
    int cnt = 2;
    res[2][3] = 1;
    ha[2] = 1, ha[3] = 1, ha[4] = 1;
    for (int i = 2; i < maxn; ++i) {
        for (int j = i + 1; j < maxn; ++j) {
            if (ha[i] || ha[j] || j - i > cnt)
                continue;
            if (!ha[i] && !ha[j] && j - i == cnt) {
                printf("<--> %d %d\n", i, j);
                res[i][j] = 1;
                ha[i] = 1; ha[j] = 1; ha[i + 1] = 1; ha[j + 1] = 1;
                ++ cnt;
            }
        }
    }
    while (t --) {
        int n, m;
        scanf("%d %d", &n, &m);
        int mini = min(n, m);
        int maxi = max(n, m);
        if (!(maxi % mini))
            printf("Alice\n");
        else {
            if (res[mini][maxi])
                printf("Bob\n");
            else
                printf("Alice\n");
        }
    }
    return 0;
}
