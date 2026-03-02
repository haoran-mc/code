#include <cstdio>
const int maxn = 1e5 + 5;
//q_min为维护最小值得递增队列，q_max为维护最大值的递减队列
int a[maxn], q_max[maxn], q_min[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    while (m --) {
        long long res = 0;
        int k; scanf("%d", &k);
        //h1，t1，h2，t2分别是q_max队首队尾和q_min队首队尾
        int h1 = 1, t1 = 1;
        int h2 = 1, t2 = 1;
        q_max[1] = q_min[1] = 1;
        int j = 1;
        for (int i = 1; i <= n; i++) {
            if (q_max[t1] < i)
                ++ t1;
            if (q_min[h1] < i)
                ++ h1;
            while (j < i || a[q_max[t1]] - a[q_min[h1]] <= k) {
                if (j == n)
                    break;
                ++ j;
                while (t2 >= t1 && a[q_max[t2]] < a[j])
                    -- t2; //维护单调递减队列
                while (h2 >= h1 && a[q_min[h2]] > a[j])
                    -- h2; //维护单调递增队列
                q_max[++t2] = j;
                q_min[++h2] = j;
            }
            if (a[q_max[t1]] - a[q_min[h1]] <= k)
                break;
            res += n - j + 1;//j后面的所有右区间都满足条件
        }
        printf("%lld\n", res);
    }
    return 0;
}
