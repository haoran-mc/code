#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
ll prime[100];
int cnt;
void init(int m) {
     cnt=0;
    for(ll i=2;i*i<m;i++)
    if(m%i==0){
        prime[cnt++]=i; //prime储存素因子，cnt为素因子的个数
        while(m%i==0){
          m/=i;
        }
    }
    if(m>1)
        prime[cnt++]=m; //这里是因为有的n的因子大于sqrt(n)，比如14，他的素因子有2，7
}

ll in_exclusion(ll cur) {
    ll res,ans=0;
    for(ll i=1;i<ll(1<<cnt);i++) {
        res=1;
        ll flag=0;
        for(ll j=0;j<cnt;j++) {
            if (i & (ll(1<<j))) { //出现因子
                flag++;           //统计出现的集合个数
                res*=prime[j];    //取并之后的因子乘积
            }
        }
        flag & 1 ? ans += cur/res : ans -= cur/res;
    }
    return ans;
}

int main() {
    ll t;
    cin>>t;
    int icase=0;
    while(t--){
        memset(prime,0,sizeof(prime));
        ll a,b,n;
        cin>>a>>b>>n;
        init(n);
        printf("Case #%d: %lld\n",++icase,b-in_exclusion(b)-(a-1-in_exclusion(a-1)));
    }
    return 0;
}
