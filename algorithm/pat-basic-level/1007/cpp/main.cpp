#include <cstdio>

const int maxn = 1e5 + 5;
int p[maxn], cnt;
bool sifter[maxn];

// 欧拉筛
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!sifter[i])
            p[cnt++] = i;

        for (int j = 0; p[j] * i <= n; j++) {
            sifter[p[j] * i] = true;

            if (i % p[j] == 0)
                break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    get_primes(n);

    int res = 0;
    for (int i = 0; i < cnt - 1; i++) {
        if (p[i + 1] - p[i] == 2)
            res++;
    }
    printf("%d\n", res);
}
