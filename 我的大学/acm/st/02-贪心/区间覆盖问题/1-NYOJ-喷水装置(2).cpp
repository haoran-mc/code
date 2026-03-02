#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int t,n,k,cnt,pos,beg;double w,h,lb,xi,ri,maxv;pair<double,double> itv[maxn];bool flag;
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>w>>h;h/=2.0;pos=cnt=0;//h取一半
            for(int i=0;i<n;++i){
                cin>>xi>>ri;
                if(ri<h)continue;//ri==h也要算
                itv[pos].first=xi-sqrt(ri*ri-h*h);
                itv[pos++].second=xi+sqrt(ri*ri-h*h);
            }
            sort(itv,itv+pos);lb=0;beg=0;flag=false;
            if(itv[0].first>0){cout<<0<<endl;continue;}//按左端点排序只需查看最左边的端点是否满足条件即可，最右边的端点在下面有判断
            while(lb<w){
                maxv=0;
                for(k=beg;k<pos&&itv[k].first<=lb;++k)//itv[k].first<=lb这样保证整个区间是连续的，即草坪都会被润湿
                    maxv=max(maxv,itv[k].second);//找线段左端点在lb以内右端点能覆盖到的最远距离
                if(maxv>lb)cnt++,lb=maxv,beg=k;//如果有一条线段右端点比当前已覆盖的区间右端点lb还大，那么就更新已覆盖的右端点值，同时计数器加1
                else {flag=true;break;}//否则说明不能覆盖整个区间，直接退出，输出0
            }
            if(flag)cout<<0<<endl;
            else cout<<cnt<<endl;
        }
    }
    return 0;
}
