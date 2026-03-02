/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年03月29日 ---- 21时56分
 *   题    目：hdu2602
 *   算    法：动态规划01背包
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct Bone {
    int val;
    int vol;
} bone[maxn];
int N; //骨头数量
int V; //背包体积
//前i块骨头放在容量为j的背包里的最大价值
int dp[maxn][maxn];

int solve() {
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= V; ++j) {
            if (bone[i].vol > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-bone[i].vol] + bone[i].val);
        }
    return dp[N][V];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &N, &V);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &bone[i].val);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &bone[i].vol);
        printf("%d\n", solve());
    }
    return 0;
}
