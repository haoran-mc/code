#include <cstdio>
#include <algorithm>
using namespace std;
//#define bug printf("<------>\n");
//const int INF = 0x3f3f3f3f;
int w[1005];
int v[1005];
int dp[50005];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &w[i], &v[i]);
    for (int i = 1; i <= m; ++i)
        dp[i] = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= w[i]; --j)
            //if (dp[j-w[i]] != -INF)
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    sort(dp, dp + m + 1);
    printf("%d", dp[m]);
    return 0;
}
