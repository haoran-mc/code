#include<iostream>
using namespace std;
int main()
{
    int n,cnt=0,num;
    cin>>n;
    while(n-cnt){
        cin>>num;
        cnt++;
        if(num%2)
            num++;
        cout<<num/2<<endl;
    }
    return 0;
}