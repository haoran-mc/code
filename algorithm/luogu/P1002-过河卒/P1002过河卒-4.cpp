/*----------------------------------------------------------------
 *
 *   文件名称：P1002过河卒-4.cpp
 *   创建日期：2020年10月10日 ---- 17时28分
 *   题    目：luogu
 *   算    法：动态规划，滚动数组
 *   描    述：自己写一遍滚动数组
 *
----------------------------------------------------------------*/

#include <cstdio>

typedef long long ill;
const int maxn = 23;
int bx;
int by;
int horsex;
int horsey;
ill dp[2][maxn];
int nextx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int nexty[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
bool vis[maxn][maxn];

ill DynamicProgramming() {
    for (int i = 0; i < 9; i++)
        vis[horsex + nextx[i]][horsey + nexty[i]] = true;

    dp[1][2] = 1;    //dp[2][1] = 1;
    for (int i = 2; i <= bx; i++) {
        for (int j = 2; j <= by; j++) {
            if (vis[i][j] == true) {
                dp[i & 1][j] = 0;
                continue;
            }
            dp[i & 1][j] = dp[(i-1) & 1][j] + dp[i & 1][j - 1];
        }
    }

    return dp[bx & 1][by];
}

int main()
{
    scanf("%d", &bx);
    scanf("%d", &by);
    scanf("%d", &horsex);
    scanf("%d", &horsey);
    bx += 2;
    by += 2;
    horsex += 2;
    horsey += 2;
    ill ans = DynamicProgramming();
    printf("%lld\n", ans);
    return 0;
}
