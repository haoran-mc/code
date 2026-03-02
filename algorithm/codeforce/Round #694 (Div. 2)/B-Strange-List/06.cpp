#include <cstdio>
const int maxn = 1e5 + 5;
int arr[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        long long sum = 0;
        for (int i = 0, j = 1; arr[i]%j == 0; ++i, i %= n) {
            sum += arr[i];
            if (i + 1 == n)
                j *= x;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
