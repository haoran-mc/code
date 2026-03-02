#include<iostream>
using namespace std;
int main(){
    unsigned long long n,x,y,t;
    cin>>n>>x>>y;
    if(x+y+1<=n){
        if((x+y)%2==0){
            t=(x+y)/2*(x+y+1)+x;
        }else{
            t=(x+y+1)/2*(x+y)+x;
        }
    }else{
        unsigned long long a,b;
        if(n%2==0)
            a=n/2*(n+1);
        else
            a=(n+1)/2*n;
        if((x+y-n)%2==0)
            b=(x+y-n)/2*(3*n-x-y-1);
        else
            b=(3*n-x-y-1)/2*(x+y-n);
        t=a+b+n-y-1;
    }
        if(10<=t%16&&t%16<=15)
            cout<<t%16<<endl;
        else
            cout<<t%16+t/16*10;
    return 0;
}
