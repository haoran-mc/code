#include <cstdio>
const int maxn = 105;
int arr1[maxn];
int arr2[maxn];
int main()
{
    int t;
    int sum = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < t; ++i)
        scanf("%d", &arr2[i]);
    for (int i = 0; i < t; ++i)
        if (arr1[i] != arr2[i])
            ++sum;
    printf("%d\n", sum);
    return 0;
}
