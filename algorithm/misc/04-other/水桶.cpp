#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ill;
bool cmp(int a,int b);
int main()
{
    int t,num,pours;
    ill a[200100];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>num>>pours;                //num为桶的数量，pours为倒水的次数
        for(int i=0;i<num;i++)
            cin>>a[i];
        sort(a,a+num,cmp);          //按照含水量从大到小排序

        for(int i=1;i<=pours;i++)
            a[0]=a[0]+a[i];         //为求最大差值，从含水第二多的桶开始，每次把全部的水倒进含水第一多的桶

        cout<<a[0]<<endl;           //因每次都倒全部的水，所以一定存在几个含水量为0的空桶，即最小值，倒完后第一个桶的水量减去0即为最大差值
    }
    return 0;

}
bool cmp(int a,int b)
{
    //if(a<b)
        //return false;
    return a > b;
}

