#include <cstdio>
#include <cmath>
int main() {
    long long res = 1; 
    int cnt = 19;
    while (cnt --) {
        res *= 3;
    }
    printf("%lld\n", res);
    // printf("%lld\n", (long long)pow(3, 10));
    int n; scanf("%d", &n);
    return 0;
}
