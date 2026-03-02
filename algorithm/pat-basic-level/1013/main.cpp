#include <cstdio>
const int maxn = 1e7 + 5;
int p[maxn], cnt = 1;
bool sifter[maxn];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!sifter[i]) {
            p[cnt++] = i;
        }

        // 非素数是素数的乘积，所以不用筛（非素数*i）
        for (int j = 1; p[j] * i <= n; j++) {
            // 筛 p[j]*i
            sifter[p[j] * i] = true;

            if (i % p[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    get_primes(maxn-1);

    for (int i = m; i <= n; i++) {
        if (i == n || (i - m + 1) % 10 == 0) {
            printf("%d\n", p[i]);
        } else {
            printf("%d ", p[i]);
        }
    }
    return 0;
}
