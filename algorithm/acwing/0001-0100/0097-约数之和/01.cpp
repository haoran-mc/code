/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月21日 星期五 22时57分12秒
 *   题    目：AcWing 97 约数之和
 *   算    法：<++>
 *   描    述：A = p1^k1 * p2^k2 * ... * pn^kn
 *
 *      约数之和(A的因子)：
 *      (p1^0 + p1^1 + ... + p1^k1) * (p2^0 + p2^1 + ... + p2^k2) * ... * (pn^0 + pn^1 + ... +pn^kn)
 *
 *      约数个数(A的因子)：
 *      (k1 + 1) * (k2 + 1) * ... * (kn + 1)
 *
 *      !!!计算(p^0 + p^1 + .. + p^k)是有模板的
 *      sum(p, k) = p^0 + p^1 + ... + p^k
 *                = (p^0 + .. + p^(k/2)) + (p^(k/2+1) + .. + p^k)
 *                = (p^0 + .. + p^(k/2)) + p^(k/2+1) * (p^0 + .. + p^(k/2))  (这里k是奇数，所以k/2 + k/2 + 1 = k)
 *                = (1 + p^(k/2+1) * sum(p, k/2)
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int mod = 9901;

int binPow(int base, int expo) {
    base %= mod;
    int res = 1;
    while (expo) {
        if (expo & 1)
            res = res * base % mod;
        base = base * base % mod;
        expo >>= 1;
    }
    return res;
}

//计算(p^0 + p^1 + p^2 + ... + p^k)
int sum(int p, int k) {
    if (k == 0)
        return 1;
    //由于式子是从0开始的，所以这里是判断是否为奇数个加数
    if (k % 2 == 0)
        //这里是将式子相左移一项，最后再加上一个p^0 = 1(妙呀)
        return (p % mod * sum(p, k-1) % mod + 1) % mod;
    //否则式子就是偶数个
    return (1 + binPow(p, k/2 + 1)) * sum(p, k/2) % mod;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int res = 1;
    //i是A的因子
    for (int i = 2; i <= A; ++i) {
        int cnt = 0; //如果i是A的因子，记录i的个数
        while (A % i == 0) {
            ++cnt;
            A /= i;
        }
        //如果i是A的因子，那么就开始计算(i^0 + i^1 + ... + i^(cnt*B))
        if (cnt) res = res * sum(i, cnt*B) % mod;//(A^B)的因子
    }
    if (!A) res = 0;
    printf("%d\n", res);
    return 0;
}
