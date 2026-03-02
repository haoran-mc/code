#include <cstdio>
const int maxn = 1e5+5;
typedef long long ill;
ill f[maxn];

int gcd(int j, int i) {
    if (i == 0) return j;
    else        return gcd(i, j % i);
}

void buildF(int n) {
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        int j = i;
        while (j != 0) {
            sum += (j % 10);
            j /= 10;
        }
        f[i] = sum;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    ill sum = 0;
    buildF(n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            if (gcd(j, i) == 1)
                sum += f[j];
    printf("%lld\n", sum);
    return 0;
}
