#include<bits/stdc++.h>
/*#pragma GCC opyimize(2)*/
#define fastio ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
long long a[200010],num[20010];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    fastio;
    long long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        bool flag=true;
        long long x=a[0]*a[n-1];
        for(long long i=1,j=n-2;i<=j;i++,j--){
            if(a[i]*a[j]!=x) {
                flag = false;
                break;
            }
        }
        if(flag){
            long long sum=0;
            for(long long i=2;i<sqrt(x);i++){
                if(x%i==0){
                    sum+=2;
                }
            }
            if(sqrt(x)*sqrt(x)==x){
                sum++;
            }
            if(sum==n){
                cout<<x<<endl;
            }
            else cout<<"-1"<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}
