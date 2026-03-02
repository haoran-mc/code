#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ill;
int main()
{
    ill num[3];
    while (scanf("%lld%lld%lld", &num[0], &num[1], &num[2]) != EOF) {
        sort(num, num+3);
        if (num[0]*num[0] + num[1]*num[1] == num[2]*num[2])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
