/*----------------------------------------------------------------
 *
 *   文件名称：1-HDU-4135-Co-prime.cpp
 *   创建日期：2020年12月11日 ---- 22时06分
 *   题    目：HDU
 *   算    法：容斥原理
 *   描    述：1. 使用位运算
 *   输    入：2
 *             1 21000 105
 *             3 15 5
 *   输    出：3 5 7
 *              i = 1 j = 0                            mult = 3 res = 7000
 *              i = 2 j = 1                            mult = 5 res = 11200
 *              i = 3 j = 0 i = 3 j = 1                mult = 15 res = 9800
 *              i = 4 j = 2                            mult = 7 res = 12800
 *              i = 5 j = 0 i = 5 j = 2                mult = 21 res = 11800
 *              i = 6 j = 1 i = 6 j = 2                mult = 35 res = 11200
 *              i = 7 j = 0 i = 7 j = 1 i = 7 j = 2    mult = 105 res = 11400
 *              res = 11400
 *              i = 1 j = 0                            mult = 3 res = 0
 *              i = 2 j = 1                            mult = 5 res = 0
 *              i = 3 j = 0 i = 3 j = 1                mult = 15 res = 0
 *              i = 4 j = 2                            mult = 7 res = 0
 *              i = 5 j = 0 i = 5 j = 2                mult = 21 res = 0
 *              i = 6 j = 1 i = 6 j = 2                mult = 35 res = 0
 *              i = 7 j = 0 i = 7 j = 1 i = 7 j = 2    mult = 105 res = 0
 *              res = 0
 *             Case #1: 9600
 *             5
 *              i = 1 j = 0                            mult = 5 res = 3
 *              res = 3
 *              i = 1 j = 0                            mult = 5 res = 0
 *              res = 0
 *             Case #2: 10
 *
 *  0-21000内3的倍数有7000个，3可以分为1×3，素因子只有一个3，根据容斥原理，使用加法
 *  0-21000内5的倍数有4200个，5可以分为1×5，素因子只有一个5，根据容斥原理，使用加法
 *  0-21000内15的倍数有1400个，3可以分为3×5，素因子有3和5，根据容斥原理，使用减法
 *  ......
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;

vector<int> primeFactor;
template<typename T>
void PrimeFactor(T num) {
    for (T i = 2; pow(i, 2) <= num; ++i)
        if (!(num % i)) {
            primeFactor.push_back(i);
            while (!(num % i)) num /= i;
        }
    if (num > 1) primeFactor.push_back(num);
    /*primeFactor.clear();*/
}

/*在0-sect区间内与N不互质数的个数*/
/*也就是和N有相同的非零共因子，即primeFactor数组*/
LL in_exclusion(LL sect) {
    LL res = 0;
    for (LL i = 1; i < LL(1 << (int)primeFactor.size()); ++i) {   // (1 << (int)primeFactor.size())这个数一定比N的最大的因子大
        LL mult = 1;
        LL cnt = 0;
        for (LL j = 0; j < (int)primeFactor.size(); ++j)
            if (i & (LL(1 << j))) {       //出现因子
                ++cnt;                    //统计出现的集合个数
                mult *= primeFactor[j];   //取并之后的因子乘积
                printf(" i = %lld j = %lld", i, j);
            }

        cnt & 1 ? res += sect/mult : res -= sect/mult;
        printf("                            mult = %lld res = %lld\n", mult, res);
    }
    printf(" res = %lld\n", res);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    LL t;
    scanf("%lld", &t);
    for (int i = 1; i <= t; ++i) {
        LL A;
        LL B;
        LL N;
        scanf("%lld", &A);
        scanf("%lld", &B);
        scanf("%lld", &N);
        PrimeFactor(N);
        for (int i = 0; i < (int)primeFactor.size(); ++i)
            printf("%d ", primeFactor[i]);
        printf("\n");
        printf("Case #%d: %lld\n", i, B-in_exclusion(B)-(A-1-in_exclusion(A-1)));
        primeFactor.clear();
    }
    return 0;
}
