#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[30001];//dp[i]表示质量为i时的最大价值
struct bag{
 int v;
 int p;
}a[1005];
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N,m,i,j;
    scanf("%d%d",&N,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d",&a[i].v,&a[i].p);
    memset(dp, 0, sizeof(dp));
    for(i=1;i<=m;i++){
        for(j=N;j>=a[i].v;j--){
            dp[j]=max(dp[j-a[i].v]+a[i].v*a[i].p,dp[j]);
        }//确定要不要买价格为j的第i件物品，总是使dp的值最大
    }
    printf("%d",dp[N]);

}
