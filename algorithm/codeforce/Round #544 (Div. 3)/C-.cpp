#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int ans[maxn];

int main(){
    int n;
    scanf("%d",&n);
    //int *a=new int[n];
    //int *ans=new int[n];
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a, a+n);
    int pos=0;
    ans[0] = 1;
    for(int i=1;i<n;++i){
        if(a[i]-a[pos]<=5)
            ans[i]=ans[i-1]+1;
        else{
            while(a[i]-a[pos]>5)
                ++pos;
            ans[i]=i-pos+1;
        }
    }
    int res = 0;
    for(int i=0;i<n;++i){
        res=max(res,ans[i]);
    }
    printf("%d\n",res);
    return 0;
}
