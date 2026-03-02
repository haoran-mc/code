#include <cstdio>
const int maxn = 1e2 + 5;

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    for (int i = 2; i < maxn; ++i) {
        if (!(is_prime(i) || is_prime(i + i + 1) || is_prime(i + i - 1)))
            printf("%d\n", i);
    }
    return 0;
}
