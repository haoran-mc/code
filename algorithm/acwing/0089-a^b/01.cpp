/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月08日 ---- 15时48分
 *   题    目：CH0101
 *   算    法：快速幂
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
typedef long long ll;
int mod;

ll binPow(ll base, ll expo) {
    ll res = 1;
    while (expo) {
        if (expo & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        expo >>= 1;
    }
    return res % mod;
}

int main() {
    int a, b;
    scanf("%d %d %d", &a, &b, &mod);
    int res = (int)binPow((ll)a, (ll)b);
    printf("%d\n", res % mod);
    return 0;
}
