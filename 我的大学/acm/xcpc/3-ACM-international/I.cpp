#include <cstdio>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int a;
        int b;
        int d;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &d);
        printf("%f\n", (double)d * (double)d / 2.0);
    }
    return 0;
}
