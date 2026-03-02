 #include<bits/stdc++.h>
 using namespace std;
 int N,W,v,w,dp[1005];
 int main(){
     //freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
     memset(dp, -0x3f, sizeof(dp));
     dp[0]=0;//背包容量为0时其最大价值为0
     scanf("%d %d",&N,&W);
     for(int i=1; i<=N; i++){
         scanf("%d%d",&w,&v);
         for(int j=w; j<=W; j++)
             dp[j]=max(dp[j], dp[j-w]+v);
     }
     printf("%d",dp[W]);
     return 0;
 }
