/*----------------------------------------------------------------
 *   
 *   文件名称：lhr01.cpp
 *   创建日期：2021年06月03日 星期四 22时06分49秒
 *   题    目：AcWing 0109 天才ACM
 *   算    法：倍增
 *   描    述：倍增的区间是左闭右闭的，自己盲写了一遍
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
    for(int i = l; i <= r; ++i)
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
        int st = 0, ed = 0;  //确定好是左闭右闭
        int res = 0;
        while (st < n) {
            int len = 1;
            while (len) {
                if (ed + len < n && judge(st, ed + len) <= T)
                    ed += len, len <<= 1;
                else
                    len >>= 1;
            }
            st = ed + 1;
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}
