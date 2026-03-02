#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float x1,y1,x2,y2,x3,y3;
    float x,y;
    float p,a,b,c;
    cin>>x1>>y1>>x2>>y2>>x3>>y3; 
    x=fabs(x2-x1);
    y=fabs(y2-y1);
    a=sqrt(x*x+y*y);
    x=fabs(x3-x2);
    y=fabs(y3-y2);
    b=sqrt(x*x+y*y);
    x=fabs(x3-x1);
    y=fabs(y3-y1);
    c=sqrt(x*x+y*y);
    p=(a+b+c)/2;
    float s;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(2);
    cout<<s;
    return 0;
}
