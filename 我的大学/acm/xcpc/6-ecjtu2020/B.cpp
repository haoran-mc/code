#include <cstdio>
typedef long long ill;
const int mod = 1e9+7;

bool judge(ill num) {
    if (!(num % 6))
        return false;
    else {
        int sum = 0;
        int base;
        while (num) {
            base = num % 10;
            if (base == 6)
                return false;
            sum += base;
            num /= 10;
            //printf("base = %d\n", base);
            //printf("num  = %lld\n", num);
            //printf("sum  = %d\n", sum);
        }
        if (!(sum % 6))
            return false;
    }
    return true;
}
/*
 *
 *ill binaryPow(ill base, ill expo, ill p) {
 *    if (expo == 0) return 1;
 *
 *    if (expo % 2 == 1)
 *        return base * binaryPow(base, expo-1, p) % p;
 *    else {
 *        ill mul = binaryPow(base, expo/2, p) % p;
 *        return mul % p * mul % p;
 *    }
 *}
 *
 *ill inv(ill b) {
 *    return binaryPow(b, mod-2, mod);
 *}
 */

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ill L;
    ill R;
    while (scanf("%lld%lld", &L, &R) != EOF) {
        ill res = 0;
        for (ill i = L; i <= R; ++i) {
            if (!(judge(i)))
                continue;
            else {
                res += i*i*i;
                res %= mod;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
