/*----------------------------------------------------------------
 *   
 *   文件名称：01-单调栈.cpp
 *   创建日期：2021年08月02日 星期一 21时56分58秒
 *   题    目：<++>
 *   算    法：单调栈
 *   描    述：存的是下标，这样很不错
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int h[maxn], l[maxn];
ll preS[maxn];
int stk[maxn], tt;

signed main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
        preS[i] = preS[i - 1] + h[i];
    }

    ll mini = 0;
    for (int i = 1; i <= n; ++i) {
        while (tt && h[i] < h[stk[tt]]) {
            mini = max(mini, (ll)(preS[i - 1] - preS[l[stk[tt]]]) * (ll)h[stk[tt]]);
            --tt;
        }
        l[i] = stk[tt];
        stk[++tt] = i;
    }
    printf("%lld\n", mini);
    return 0;
}
