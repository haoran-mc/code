#include <cstdio>
#include <cmath>
int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n; scanf("%d", &n);
        int res = 0;
        // 往后
        res += ((n + 1) / 2);
        int l = ceil((n - 1) / 3);
        res += (n - l + 1) / 2;
        // res += (n - ((n - 1) / 3)) / 2;
        printf("%d\n", res);
    }
    return 0;
}
