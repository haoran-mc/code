#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
const int mod  = 1e9 + 7;
int wind[maxn];

int sum(int L, int R) {
    long long res = 0;
    for (long long i = L; i <= R; ++i) {
        res += wind[i];
        res %= mod;
    }
    return res;
}

int main() {
    int n;
    int d;
    scanf("%d", &n);
    scanf("%d", &d);
    wind[1] = 1;
    for (int i = 2; i <= n; ++i)
        wind[i] = sum(max(i-d, 1), i-1);
    printf("%d\n", wind[n]);
    return 0;
}
