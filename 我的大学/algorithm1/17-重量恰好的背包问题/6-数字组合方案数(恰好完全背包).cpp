#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define bug printf("<------>\n");
const int INF = -2147483647;
//#define INF 0x7fffffff
int w[1005],v[1005],dp[50005];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int m;
    scanf("%d %d", &n, &m);
    //后期全靠dp[0]==0了
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        scanf("%d %d",&w[i],&v[i]);
    //除dp[0]外，其余均初始化为无穷
    for (int i=1;i<=m;i++)
        dp[i] = INF;
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        //倒序更新,对于重量w[i]小于j的不作更新
        for(int j=m;j>=w[i];j--){
            //choice[i][j] = true;//如需记录，则可另创一个辅助数组(详见下文)
            if (dp[j-w[i]] != INF)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    printf("%d", dp[m]);
    return 0;
}
