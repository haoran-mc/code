/*----------------------------------------------------------------
 *
 *   文件名称：P1002过河卒.cpp
 *   创建日期：2020年10月09日 ---- 20时48分
 *   题    目：luogu
 *   算    法：动态规划
 *   描    述：1. 马的点也不允许通过
 *             2. 第一行与第一列不一定全是1
 *             3. 马的控制点可能在界外
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ill;
typedef unsigned long long ull;
const int maxn = 21;
const int nextx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
const int nexty[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
int horsex;
int horsey;
int bx;
int by;
ill dp[maxn][maxn];

bool judge(int x, int y) {
    for (int i = 0; i < 9; i++)
        if (x == horsex + nextx[i] && y == horsey + nexty[i])
            return true;

    return false;
}

ill DynamicProgramming() {
    for (int i = 0; i < 9; i++)
        if (horsex + nextx[i] >= 0 && horsey + nexty[i] >= 0)
            dp[horsex + nextx[i]][horsey + nexty[i]] = -1;

    for (int i = 0; i <= bx; i++) {
        if (judge(i, 0) == true)
            break;
        dp[i][0] = 1;
    }
    for (int j = 0; j <= by; j++) {
        if (judge(0, j) == true)
            break;
        dp[0][j] = 1;
    }

    for (int i = 1; i <= bx; i++) {
        for (int j = 1; j <= by; j++) {
            if (dp[i][j] == -1)
                continue;

            if (dp[i - 1][j] == -1 && dp[i][j - 1] != -1)
                dp[i][j] = dp[i][j - 1];
            else if (dp[i][j - 1] == -1 && dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][j];
            else if (dp[i][j - 1] == -1 && dp[i - 1][j] == -1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[bx][by];
}

int main()
{
    scanf("%d", &bx);
    scanf("%d", &by);
    scanf("%d", &horsex);
    scanf("%d", &horsey);
    ill ans = DynamicProgramming();
    printf("%lld\n", ans);
    /*
     *for (int i = 0; i <= bx; i++) {
     *    for (int j = 0; j <= by; j++) {
     *        printf("%lld ", dp[i][j]);
     *    }
     *    printf("\n");
     *}
     */
    return 0;
}

