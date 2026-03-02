#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=105;
int n,tmp,ans;pair<int,int> itv[maxn];
int main(){
    while(cin>>n){
        for(int i=0;i<n;++i)cin>>itv[i].first>>itv[i].second;
        sort(itv,itv+n);tmp=itv[0].second;ans=1;
        for(int i=0;i<n;++i){
            if(tmp<itv[i].first)ans++,tmp=itv[i].second;
            else if(tmp>itv[i].second)tmp=itv[i].second;
        }
        cout<<ans<<endl;
    }
    return 0;
}
