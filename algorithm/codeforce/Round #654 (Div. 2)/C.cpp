#include<iostream>
using namespace std;
int main()
{
    int amount;
    long long n_guest,m_guest,chocolate,vanilla;
    long long more,less;
    cin>>amount;
    while(amount--){
        cin>>vanilla>>chocolate>>n_guest>>m_guest;
        if(vanilla+chocolate<n_guest+m_guest)
            cout<<"No"<<endl;
        else{
            if(vanilla>chocolate)
                (more=vanilla,less=chocolate);
            else
                (more=chocolate,less=vanilla);
            if(m_guest<=less)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}