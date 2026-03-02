#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=10005;
int t,n,tmp,ans;pair<int,int> itv[maxn];
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=0;i<n;++i)cin>>itv[i].second>>itv[i].first;
            sort(itv,itv+n);tmp=-1;ans=0;//按结束时间早进行排序
            for (int i = 0; i < n; ++i)
                printf("%d %d\n", itv[i].second, itv[i].first);
            for(int i=0;i<n;++i)
                if(tmp<itv[i].second)ans++,tmp=itv[i].first;
            cout<<ans<<endl;
        }
    }
    return 0;
}
