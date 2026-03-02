#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int prog[maxn];
int hach[maxn];

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
    for (int i = 1; i < n; ++i)
        if (prog[i] >= i+1)
            ++res;
    printf("%d\n", res);
    return 0;
}
