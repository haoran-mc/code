/*----------------------------------------------------------------
 *
 *   文件名称：A-牛牛和牛可乐的赌约.cpp
 *   创建日期：2020年09月19日 ---- 19时26分
 *   题    目：nowcoder
 *   算    法：逆元
 *   描    述：求一个较复杂的逆元
 *
----------------------------------------------------------------*/

#include <cstdio>

typedef long long ill;
const ill mod = 1e9 + 7;

ill binaryPow(ill base, ill expo) {
    if (expo == 0)
        return 1;

    if (expo % 2 == 1)
        return base * binaryPow(base, expo - 1) % mod;
    else {
        int mul = binaryPow(base, expo / 2) % mod;
        return mul % mod * mul % mod;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        ill n;
        ill m;
        scanf("%lld", &n);
        scanf("%lld", &m);
        ill ans1 = binaryPow(n, m + m * (mod - 2));
        ill ans2 = binaryPow(n, m * (mod - 2));
        ill ans  = ans1 - ans2;
        if (ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }
    return 0;
}
