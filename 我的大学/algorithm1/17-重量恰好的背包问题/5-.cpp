#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = -2147483647;
int w[2100],v[2100],dp[51000];
/*
 *int max(int a, int b) {
 *    return a > b ? a : b;
 *}
 */

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    int m;
    scanf("%d %d", &n, &m);
    memset(dp, 0, sizeof(dp));//后期全靠dp[0]==0了
    for (int i = 1; i <= n; ++i)
        scanf("%d %d",&w[i],&v[i]);
    for (int i = 1; i <= m; ++i)
        dp[i] = INF;
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= m; ++j)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);

    printf("%d", dp[m]);
    return 0;
}
