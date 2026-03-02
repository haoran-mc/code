#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int A(int n) {
    long long res = 1;
    for (long long i = 1; i <= n; ++i) {
        res *= i;
        res %= MOD;
    }
    return (int)(res % MOD);
}

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        int n; scanf("%d", &n);
        int max1 = 0, max2 = 0;   // 最大的数max1，第二大的数max2

        int cnt_max2 = 0;
        for (int i = 0; i < n; i++) {
            int _; scanf("%d", &_);
            if (_ == max2) {
                cnt_max2++;
            }
            if (_ > max2) {
                max2 = _;
                cnt_max2 = 1;
            }
            if (max2 > max1) {
                swap(max2, max1);
                cnt_max2 = 1;
            }
        }

        printf("%d %d\n", A(n), A(n - 1));

        if (max1 > max2 + 1) {
            printf("0\n");
            continue;
        }
        if (max1 == max2)
            printf("%d\n", A(n) % MOD);
        else if (max1 == max2 + 1)
            printf("%d\n", (A(n) % MOD * (cnt_max2 - 1) / cnt_max2));
    }
    return 0;
}
