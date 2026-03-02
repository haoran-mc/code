#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 25;
int preS[maxn];

bool judge(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        int x; scanf("%d", &x);
        // 我们猜测，如果存在，那么结果小于10
        if (x < 0) {
            int cnt = 2 * (-x) + 1;
            int i = -x + 1;
            int sum = i;
            cnt++;
            while (!judge(sum)) {
                i++;
                cnt++;
                sum += i;
            }
            printf("%d\n", cnt);
            continue;
        }
        else {
            int idx = 0;
            for (int i = x - 10; i <= x + 10; ++i) {
                idx++;
                idx ? preS[idx] = preS[idx - 1] + i : preS[idx] = i;
            }
            int cnt = maxn;
            for (int i = 1; i <= idx; ++i)
                for (int j = 1; j <= idx; ++j)
                    if (i <= 11 && 11 <= j)
                        if (judge(preS[j] - preS[i-1]))
                            cnt = min(cnt, j - i + 1);
            printf("%d\n", cnt);
        }
    }
    return 0;
}
