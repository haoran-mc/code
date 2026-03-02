#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e7 + 10;
int primes[maxn], cnt; // primes[]存储所有素数
bool st[maxn];         // st[x]存储x是否被筛掉
int ans[maxn];
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int cal(int x) {
    if (!st[x])
        return 1;
    if (!st[x + x + 1])
        return 2;
    return 2 + cal(x + 1);
}

int cal1(int x) {
    if (!st[x])
        return 1;
    else {
        if (!st[x + x + 1])
            return 2;
        return 2 * x + 1 + cal(x + 1);
    }
}
int main() {
    get_primes(maxn - 1);
    ans[0] = 3;
    ans[1] = 2;
    for (int x = 2; x <= maxn / 2; ++x) {
        if (!st[x])
            ans[x] = 1;
        else {
            if (!st[x + x - 1] || !st[x + x + 1])
                ans[x] = 2;
            else
                ans[x] = 2 * x + 1 + cal(x + 1);
        }
    }
    int t; scanf("%d", &t);
    while (t --) {
        int x; scanf("%d", &x);
        if (x >= 0)
            cout << ans[x] << '\n';
        else {
            if (ans[-x + 1] == 1)
                cout << -2 * x + 1 + 1 << '\n';
            else {
                int t = cal1(-x + 1);
                if (t <= 2)
                    cout << -2 * x + 1 + t << '\n';
                else
                    cout << t << '\n';
            }
        }
    }
    return 0;
}
