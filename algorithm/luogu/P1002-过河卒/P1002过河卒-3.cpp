/*----------------------------------------------------------------
 *
 *   文件名称：P1002过河卒-3.cpp
 *   创建日期：2020年10月10日 ---- 17时08分
 *   题    目：luogu
 *   算    法：动态规划，滚动数组
 *   描    述：1. 如果前两行，前两列不使用的话，马在边界的情况就不用考虑了
 *
----------------------------------------------------------------*/

#include<cstdio>

typedef long long ill;
const int nextx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int nexty[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int bx;
int by;
int horsex;
int horsey;
ill dp[2][23];  //第一维大小为 2 就好
bool coord[23][23];

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
    dp[1][2] = 1;

    for (int i = 0; i < 9; i++)
        coord[horsex + nextx[i]][horsey + nexty[i]] = true;

    for (int i = 2; i <= bx; i++) {
        for (int j = 2; j <= by; j++) {
            if (coord[i][j] == true) {
                dp[i & 1][j] = 0;  //被马拦住了记住清零
                continue;
            }
            dp[i & 1][j] = dp[(i-1) & 1][j] + dp[i & 1][j-1];
        }
    }
    printf("%lld\n", dp[bx & 1][by]);
    //输出的时候第一维也要 按位与 一下,即 bx&1
    return 0;
}
