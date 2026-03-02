#include <cstdio>
const int maxn = 1e5 + 5;

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int sum = 0;
    for (int i = 28; i < maxn; ++i) {
        sum += i;
        if (is_prime(sum)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
