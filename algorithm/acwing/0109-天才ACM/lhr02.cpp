/*----------------------------------------------------------------
 *   
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：0033-天才ACM.cpp
 *   创建日期：2021年06月03日 星期四 22时17分08秒
 *   结束日期：2021年06月03日 星期四 22时18分00秒
 *   题    目：AcWing 0109 天才ACM
 *   算    法：倍增
 *   描    述：左闭右开
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, m;
ll T, I[maxn], tmp[maxn];

ll judge(int l, int r) {
    int idx = 0;
    for (int i = l; i < r; ++i)
        tmp[idx++] = I[i];
    sort(tmp, tmp + idx);
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        if (i >= idx - i - 1)
            break;
        sum += pow((tmp[i] - tmp[idx - i - 1]), 2);
    }
    return sum;
}

int main() {
    int k; scanf("%d", &k);
    while (k--) {
        scanf("%d %d %lld", &n, &m, &T);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &I[i]);
        int res = 0;
        int st = 0, ed = 0;  //左闭右开
        while (ed < n) {
            int len = 1;
            while (len) {
                if (ed + len <= n && judge(st, ed + len) <= T)
                    ed += len, len <<= 1;
                else
                    len >>= 1;
            }
            st = ed;
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
