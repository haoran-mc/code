#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int maxn = 1e6+5;
int color[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    int sum0 = 0;
    int sum1 = 0;
    int sum  = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &color[i]);
    for (int i = 0; i < n; i += 2)
        if (color[i] == color[i+1])
            ++sum0;
    for (int i = 1; i < n; i += 2)
        if (color[i] == color[i+1])
            ++sum1;
    sum += (((sum0 - 1) * sum0) / 2);
    sum += (((sum1 - 1) * sum1) / 2);
    sum += sum0;
    sum += sum1;
    printf("%d\n", sum);
    return 0;
}
