#include <cstdio>
typedef long long ll;
const int maxn = 1e7 + 5;
int seek = 0;
int prime[maxn];
//最终为false的数是素数
bool sifter[maxn];

void sievePrime() {
    for (int i = 2; i <= maxn; i++) {
        if (sifter[i] == false)
            prime[seek++] = i;

        for (int j = 0; j < seek; j++) {
            if (i * prime[j] > maxn)
                break;
            sifter[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll res[maxn];

int main() {
    sievePrime();
    res[2] = 0;
    for (int i = 3; i < maxn; ++i) {
        if (sifter[i])
            res[i] = res[i-1] + i;
        else
            res[i] = res[i-1] + 2 * i;
    }
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        printf("%lld\n", res[n]);
    }
    return 0;
}
