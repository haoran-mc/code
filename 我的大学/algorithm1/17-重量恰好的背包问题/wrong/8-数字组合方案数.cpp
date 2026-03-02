#include <cstdio>
const int maxn = 105;
int num[maxn];
int dp[maxn]; //组成数字i的组合的个数
int res;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int t = m; t >= 0; --t)
            if (t >= num[i])
                dp[t] += dp[t-num[i]];
    printf("%d", dp[m]);
    return 0;
}
