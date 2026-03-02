#include <cstdio>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k >= n) {
        printf("2\n");
        return 0;
    }
    if (2 * n % k)
        printf("%d\n", 2 * n / k + 1);
    else
        printf("%d\n", 2 * n / k);
    return 0;
}
