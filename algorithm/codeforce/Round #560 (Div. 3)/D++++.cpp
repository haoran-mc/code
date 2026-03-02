/*----------------------------------------------------------------
 *
 *   文件名称：D++++.cpp
 *   创建日期：2020年12月20日 ---- 15时47分
 *   题    目：codeforces
 *   算    法：整数的所有因子排序后，divi[0] * divi[n-1] = x
 *   描    述：
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define bug printf("<------>\n");
typedef long long LL;
const int maxn = 1e6 + 5;
LL divi[maxn];
bool hach[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(hach, 0, sizeof(hach));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &divi[i]);
            hach[divi[i]] = true;
        }
        sort(divi, divi + n);
        LL x = divi[0] * divi[n-1];
        /*printf("\nn = %d ", n);*/
        /*printf("divi[0] = %lld divi[n-1] = %lld ", divi[0], divi[n-1]);*/
        /*printf("x = %lld\n", x);*/
        bool flag = true;
        for (LL i = 1; 2 * i < n; ++i)
            if (divi[i] * divi[n-1-i] != x) {
                flag = false;
                break;
            }
        if (flag)
            /*bug*/
            for (LL i = 2; pow(i, 2) <= x; ++i)
                if (!(x % i))
                    if (!hach[i] || !hach[x / i]) {
                        flag = false;
                        break;
                    }
        flag ? printf("%lld\n", x) : printf("-1\n");
    }
    return 0;
}
