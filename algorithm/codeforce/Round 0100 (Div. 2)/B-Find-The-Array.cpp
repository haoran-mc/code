#include <cstdio>
const int maxn = 55;
int arr[maxn];

int main() {
#ifndef ONLINUE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
    }
    return 0;
}
