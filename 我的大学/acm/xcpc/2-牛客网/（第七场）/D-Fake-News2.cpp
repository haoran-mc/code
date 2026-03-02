#include <cstdio>
#include <cmath>

typedef long long LL;

int main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        LL num;
        scanf("%lld", &num);

        if (num == 1 || num == 24)
            printf("Fake news!\n");

        else
            printf("Nobody knows it better than me!\n");
    }
    return 0;
}
