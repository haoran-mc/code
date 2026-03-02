#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int inf  = 0x3f3f3f3f;
int part[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int maxi = 0;
        int mini = inf;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &part[i]);
            sum += part[i];
            maxi = max(maxi, part[i]);
            mini = min(mini, part[i]);
        }
        int AKL = m - (n * m - sum);
        if (AKL < 0)
            AKL = 0;
        int AKR = mini;
        int ZEL = m - sum;
        if (ZEL < 0)
            ZEL = 0;
        int ZER = m - maxi;
        printf("%d %d\n", AKL, AKR);
        printf("%d %d\n", ZEL, ZER);
    }
    return 0;
}
