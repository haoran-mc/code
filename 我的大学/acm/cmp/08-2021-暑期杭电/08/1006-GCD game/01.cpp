#include <cstdio>
const int maxn = 1e7 + 5;
#define bug printf("<-->\n");
int primes[maxn], tot;
bool sifter[maxn];
bool st[maxn];
int a[maxn];

bool judge(int x) {
    int f = 0;
    int tmp = x;
    for (int i = 2; i <= tmp / i; ++i)
        while (x % i == 0) {
            x /= i;
            ++f;
        }
    return f >= 2 ? true : false;
}

void get_primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (sifter[i] == false)
            primes[tot++] = i;

        for (int j = 0; primes[j] <= n / i; ++j) {
            sifter[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    get_primes(maxn);
    while (t--) {
        int n; scanf("%d", &n);
        int cnt1 = 0;   // 记录所有非1的个数
        int cnt2 = 0;   // 记录所有合数的个数
        int cnt3 = 0;   // 记录所有有多个质因子的合数
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] != 1)
                cnt1++;
            if (a[i] != 1 && sifter[a[i]]) {
                cnt2++;
                if (judge(a[i]))
                    cnt3++;
            }
        }
        if (!cnt1)
            printf("Bob\n");
        else if (!cnt2 && cnt1 & 1)
            printf("Alice\n");
        else if (!cnt2)
            printf("Bob\n");
        else {
            int res = 0;
            res += (cnt1 - cnt2) & 1;
            res += (cnt2 - cnt3) ^ 1;
            res += cnt3 ^ 1;
            res &= 1;
            res & 1 ? printf("Alice\n") : printf("Bob\n");
        }
        /*
         * else if (cnt2 & 1)
         *     printf("Alice\n");
         * else
         *     printf("Bob\n");
         */
    }
    return 0;
}
