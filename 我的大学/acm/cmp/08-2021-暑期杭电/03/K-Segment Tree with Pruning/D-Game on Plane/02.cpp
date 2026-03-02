#include <cstdio>
#include <cmath>

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        int cnt = 0;
        while (n > k) {
            n /= 2;
            cnt++;
        }
        printf("%d\n", cnt);
        printf("%lld\n", n / k * (long long)pow(2, cnt + 1) - 1);
    }
    return 0;
}
