#include<iostream>
using namespace std;
int main(){
    long long a1,a2,a3;
    scanf("%lld%lld%lld",&a1,&a2,&a3);
    long long ans=0;
    if(a1==a2){
        ans=a2*2;
    }else if(a1>a2){
        ans=a2*2+((a1-a2)/3) * 3;
        if((a1-a2)%3==2){
            ++ans;
        }
    }else{
        ans=a1*2+((a2-a1) / 3) * 6;
        if((a2-a1)%3==2){
            ans+=4;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
