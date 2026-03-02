#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int prog[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &prog[i]);
    sort(prog, prog + n);
    int res = 1;
    int day = 2;
    for (int i = 1; i < n; ++i)
        if (prog[i] >= day)
            ++day,
            ++res;
    printf("%d\n", res);
    return 0;
}
