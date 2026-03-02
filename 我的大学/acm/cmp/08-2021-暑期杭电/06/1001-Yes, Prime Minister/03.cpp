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
    if (is_prime(99991))
        printf("99991\n");
    /*
     * if (is_prime(99991 + 99990))
     *     printf("99991 + 99990\n");
     * if (is_prime(99991 + 99990 + 99992))
     *     printf("99991 + 99990 + 99992\n");
     * if (is_prime(99991 + 99990 + 99992 + 99993))
     *     printf("99991 + 99990 + 99992 + 99993\n");
     * if (is_prime(99991 + 99990 + 99992 + 99993 + 99994))
     *     printf("99991 + 99990 + 99992 + 99993 + 99994\n");
     * if (is_prime(99991 + 99990 + 99992 + 99993 + 99994 + 99995))
     *     printf("99991 + 99990 + 99992 + 99993 + 99994 + 99995\n");
     * if (is_prime(99991 + 99990 + 99992 + 99993 + 99994 + 99995 + 99996))
     *     printf("99991 + 99990 + 99992 + 99993 + 99994 + 99995 + 99996\n");
     * if (is_prime(99991 + 99990 + 99992 + 99993 + 99994 + 99995 + 99996))
     *     printf("99991 + 99990 + 99992 + 99993 + 99994 + 99995 + 99996\n");
     */
    int i = 99989;
    int sum = 99989 + 99990;
    while (!is_prime(sum)) {
        sum += ++i;
    }
    printf("%d\n", i);
    return 0;
}
