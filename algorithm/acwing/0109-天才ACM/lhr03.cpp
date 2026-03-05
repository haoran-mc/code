#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define bug printf("<-->\n");
#define NEXTLINE puts("");
const int maxn = 5e5 + 5;
int n, m;
ll T, I[maxn], ord[maxn], tmp[maxn];

ll judge(int l, int mid, int r) {
    for (int i = mid + 1; i <= r; ++i)
        ord[i] = I[i];
    sort(ord + mid + 1, ord + r + 1);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (ord[i] <= ord[j])
            tmp[k++] = ord[i++];
        else
            tmp[k++] = ord[j++];

    while (i <= mid)
        tmp[k++] = ord[i++];
    while (j <= r)
        tmp[k++] = ord[j++];

    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        if (i >= k - i - 1)
            break;
        sum += pow((tmp[i] - tmp[k - i - 1]), 2);
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int k; scanf("%d", &k);
    while (k--) {
        scanf("%d %d %lld", &n, &m, &T);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &I[i]);
        int res = 0;
        int st = 0, ed = 0;  //左闭右闭
        ord[0] = I[0];  //边界问题真的很重要，这里还要赋值
        while (st < n) {
            int len = 1;
            while (len) {
                if (ed + len < n && judge(st, ed, ed + len) <= T) {
                    ed += len, len <<= 1;
                    for (int i = st; i <= ed; ++i)
                        ord[i] = tmp[i - st];
                    /*
                     * printf("<-->%d %d %d  ", st, ed, len);
                     * for (int i = 0; i < n; ++i)
                     *     printf("%lld ", ord[i]);
                     * NEXTLINE;
                     */
                }
                else
                    len >>= 1;
            }
            st = ed + 1;
            ++res;
        }
        /*
         * for (int i = 0; i < n; ++i)
         *     printf("%lld ", ord[i]);
         * NEXTLINE;
         */
        printf("%d\n", res);
    }
    return 0;
}
