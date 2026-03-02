#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
int teen[maxn];
#define bug printf("<------>\n");
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &teen[i]);
    sort(teen, teen + n);
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int j = i + res;
        while (j < n && teen[j] <= teen[i] + 5)
            res = max(res, (j++)-i+1);
    }
    printf("%d\n", res);
    return 0;
}
