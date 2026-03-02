#include <cstdio>
int main()
{
    int n;
    int x;
    int y;
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    long long int a=0,b=0,sum=0;
    while(a!=n-1 && b != n-1)
    {
        sum++;
        if(b==0) {
            b=a+1;
            a=0;
        }
        else {
            a++;
            b--;
        }
    }
    if(sum>16)
        printf("%lld\n",sum+6);
    else
        printf("%lld\n",sum);
    return 0;
}

