/*----------------------------------------------------------------
 *
 *   文件名称：3-HDU-4135-Co-prime.cpp
 *   创建日期：2020年12月11日 ---- 22时08分
 *   题    目：HDU
 *   算    法：容斥原理
 *   描    述：3. 递归
 *
 ----------------------------------------------------------------*/

#include <cstdio>
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

LL Noprime(int N, LL sect, int x) {
    LL ret = 0;
    for (LL i = x; i < (int)primeFactor.size(); i++)
        ret += sect/primeFactor[i] - Noprime(N, sect/primeFactor[i], i+1);
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        LL A;
        LL B;
        LL N;
        scanf("%lld", &A);
        scanf("%lld", &B);
        scanf("%lld", &N);
        PrimeFactor(N);
        printf("Case #%d: %lld\n", i, B-Noprime(N, B, 0)-(A-1-Noprime(N, A-1, 0)));
        primeFactor.clear();
    }
    return 0;
}

