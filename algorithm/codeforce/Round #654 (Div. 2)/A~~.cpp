//题目看错了
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    for(int i=1;i<=n;i++){
        if(i%2)
            cout<<(i+1)/2<<endl;
        else
            cout<<i/2<<endl;
    }
    return 0;
}