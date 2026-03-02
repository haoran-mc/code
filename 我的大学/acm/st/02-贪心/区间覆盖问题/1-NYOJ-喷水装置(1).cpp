#include<bits/stdc++.h>
using namespace std;
int t,n,cnt;double ans,ri,dt[605];
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;ans=0;cnt=0;
            for(int i=0;i<n;++i)cin>>ri,dt[i]=ri>1?sqrt(ri*ri-1):0;//这里可以设置为0，因为题目已经保证一定可以将草坪全部润湿
            sort(dt,dt+n);
            for(int i=n-1;ans<=10.0&&i>=0;--i)cnt++,ans+=dt[i];//从后往前能选出最少数量的喷水装置，且一定能将草坪润湿
            cout<<cnt<<endl;
        }
    }
    return 0;
}
