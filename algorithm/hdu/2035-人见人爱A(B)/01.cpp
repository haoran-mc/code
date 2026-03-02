/*----------------------------------------------------------------
 *
 *   文件名称：2035.cpp
 *   创建日期：2021年03月29日 ---- 21时20分
 *   题    目：hdu2035 人见人爱A^B
 *   算    法：快速幂
 *   描    述：求A^B的最后三位数表示的整数
 *      没想到，直接对每一次运算都取模就行了，不需要求出结果后再mod1000
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int mod = 1000;
int binPow(int base, int expo) {
    if (expo == 0) return 1;

    if (expo & 1)
        return base * binPow(base, expo-1) % mod;
    else {
        int mul = binPow(base, expo/2);
        return mul * mul % mod;
    }
}

int main() {
    int base;
    int expo;
    while (scanf("%d %d", &base, &expo) && !(base == 0 && expo == 0))
        printf("%d\n", binPow(base, expo));
    return 0;
}
