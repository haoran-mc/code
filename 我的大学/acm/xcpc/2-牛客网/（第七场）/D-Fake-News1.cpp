#include <cstdio>
#include <cmath>

typedef long long LL;
const double eps = 1e-8; 

int main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        LL num;
        LL sum = 0;
        scanf("%lld", &num);
        
        for (LL i = num; i > 0; i--)
            sum += i * i;

        if ((double)sqrt((double)sum) - (LL)sqrt((double)sum) < eps)
            printf("Fake news!\n");

        else
            printf("Nobody knows it better than me!\n");
    }

    return 0;
}
