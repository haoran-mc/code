#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, m;
ll T, I[maxn], ord[maxn], tmp[maxn];

ll judge(int l, int mid, int r) {         // 判断区间 [l, r) 是否合法，并将 t 中的 [l, mid) 区间和 [mid, r) 区间合并到 tmp 中
    for (int i = mid; i < r; i++)         // 将 w 数组的 [l, r) 区间复制到 t 的 [l, r) 区间中
        ord[i] = I[i];
    sort(ord + mid, ord + r);                   // 将 t 的 [mid, r) 排序
    int i = l, j = mid, idx = 0;              // 双指针进行区间合并
    while (i != mid && j != r)              // 当 i 不到 mid 且 j 不到 r 时，执行循环
        if (ord[i] < ord[j])                    // 如果 ord[i] 比 ord[j] 小，那么将 ord[i] 放入 tmp 中
            tmp[idx++] = ord[i++];
        else                                // 否则将 ord[j] 放入 tmp 中
            tmp[idx++] = ord[j++];

    while (i != mid) 
        tmp[idx++] = ord[i++];
    while (j != r) 
        tmp[idx++] = ord[j++];

    ll sum = 0;                             // 计算校验值
    for (i = 0; i < m && i < idx; i++, idx--)
        sum += pow((tmp[i] - tmp[idx - 1]), 2);
    return sum;
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d %lld\n", &n, &m, &T);
        for (int i = 0; i < n; i++)
            scanf("%lld", &I[i]);
        int res = 0;
        int st = 0, ed = 0;
        while (ed < n) {
            int len = 1;
            while (len) {
                if (ed + len <= n && judge(st, ed, ed + len) <= T) {
                    ed += len, len <<= 1;
                    for (int i = st; i < ed; i++) // 在 judge 时，已经将 t 数组的 [st, ed + len) 这段区间归并在 tmp 中了。现在只需要将 tmp 中的有序数组复制到 t 中即可
                        ord[i] = tmp[i - st];          // 复制的时候注意下标变换，tmp 是从 0 开始存的，t 是从 st 开始存的
                }
                else
                    len >>= 1;
            }
            st = ed;
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
