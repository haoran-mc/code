#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1005;
int n,d,ans,pos,cnt=1,x,y;double tmp;
struct node{double l,r;}point[maxn];
bool cmp(node a,node b){return a.l<b.l;}
int main(){
    while(cin>>n>>d&&(n|d)){//注意这里：n|d，表示n和d同时为0时，程序才退出
        ans=1;pos=0;
        for(int i=0;i<n;++i){
            cin>>x>>y;
            if(y>d){ans=-1;continue;}//根号下只能为非负数
            point[pos].l=1.0*x-sqrt(1.0*d*d-y*y);//以每个岛屿为圆心，半径为d画圆，其与x轴最后只有两个交点
            point[pos++].r=1.0*x+sqrt(1.0*d*d-y*y);
        }
        sort(point,point+pos,cmp);tmp=point[0].r;
        for(int i=1;i<pos&&ans!=-1;++i){
            if(tmp<point[i].l){ans++;tmp=point[i].r;}//如果已选线段与当前线段不相交，那么就设置一个新的雷达，然后更新tmp为其右端点值
            else if(tmp>point[i].r)tmp=point[i].r;//可以覆盖掉下一条线段，但此时区间右端点缩短为下一条线段的右端点，说明覆盖的范围缩短了
        }
        cout<<"Case "<<cnt++<<": "<<ans<<endl;
    }
    return 0;
}
