#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int weight[maxn];//物品重量
int value[maxn];//物品价值
int dp[maxn][maxn]; //子问题状态:f[i][j]:表示前i件物品放入容量为j的背包得到的最大价值

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N;//物品个数
    int V;//背包最大容量
    scanf("%d", &N);
    scanf("%d", &V);
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &weight[i], &value[i]);
    /*
     *for (int i = 0; i <= N; ++i) //枚举物品
     *    for (int j = 0; j <= V; ++j) //枚举背包容量
     *        dp[i][j] = MinNum;
     */
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;//背包容量为0时为合法状态
    //递推 //枚举物品
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= V; ++j) { //枚举背包容量
            dp[i][j] = dp[i-1][j];
            //if (j >= weight[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }
    printf("%d", dp[N][V]);
    return 0;
}

