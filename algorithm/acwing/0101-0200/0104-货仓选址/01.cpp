#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int shop[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &shop[i]);
    sort(shop, shop + n);
    long long res = 0;
    int idx = n / 2;
    for (int i = 0; i < n; ++i) 
        res += abs(shop[i] - shop[idx]);
    printf("%lld\n", res);
    return 0;
}
