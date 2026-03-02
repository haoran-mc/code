#include <cstdio>
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if (n <= k + 1)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
