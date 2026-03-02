/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年07月30日 星期五 23时13分04秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：有规律的，1要特判一下
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cmath>
#define lowbit(x) ((x) & -(x)) //lowbit(ob0100) = 4
typedef long long ll;

ll solve(ll n) {
    ll res;
    while (n) {
        res = lowbit(n);
        n -= res;
    }
    for (int i = 0; ; ++i) 
        if (pow(2, i) == res)
            return i;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        ll expo = solve(n-1);
        // printf("%lld\n", solve(n-1));
        printf("%lld\n", (ll)pow(2.0, (double)expo) - 1);
    }
    return 0;
}
