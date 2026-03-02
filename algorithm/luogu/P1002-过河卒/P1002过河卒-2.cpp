/*----------------------------------------------------------------
 *
 *   文件名称：P1002过河卒.cpp
 *   创建日期：2020年10月09日 ---- 20时48分
 *   题    目：luogu
 *   算    法：动态规划
 *   描    述：1. 排除的情况太多了，不如从第三列开始
 *             2. 这样就不用考虑马在边缘的情况
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
bool coord[maxn][maxn];

ill DynamicProgramming() {
    for (int i = 0; i < 9; i++)
        if (horsex + nextx[i] >= 0 && horsey + nexty[i] >= 0)
            coord[horsex + nextx[i]][horsey + nexty[i]] = true;

    for (int i = 0; i <= bx; i++) {
        if (coord[i][0] == true)
            break;
        dp[i][0] = 1;
    }
    for (int j = 0; j <= by; j++) {
        if (coord[0][j] == true)
            break;
        dp[0][j] = 1;
    }

    for (int i = 1; i <= bx; i++) {
        for (int j = 1; j <= by; j++) {
            if (coord[i][j] == true)
                continue;

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
