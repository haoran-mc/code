/*----------------------------------------------------------------
 *
 *   文件名称：A1.cpp
 *   创建日期：2020年09月20日 ---- 17时33分
 *   题    目：nowcoder
 *   算    法：逆元
 *   描    述：详解请看Program-Algorithm-逆元
 *
----------------------------------------------------------------*/

#include <cstdio>

typedef long long ill;
const ill mod = 1e9 + 7;

ill binaryPow(ill base, ill expo) {
    if (expo == 0)
        return 1;

    if (expo & 1)
        return base * binaryPow(base, expo - 1) % mod;
    else {
        int mul = binaryPow(base, expo / 2) % mod;
        return mul % mod * mul % mod;
    }
}

ill inv(ill dnm) {
    return binaryPow(dnm, mod - 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        printf("%d\n", (int)(1 - binaryPow(inv((ill)n), m) + mod));
    }
    return 0;
}

