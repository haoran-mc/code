/*----------------------------------------------------------------
 *
 *   文件名称：2-HDU-4135-Co-prime.cpp
 *   创建日期：2020年12月11日 ---- 22时07分
 *   题    目：HDU
 *   算    法：容斥原理
 *   描    述：2. 队列数组
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
LL quu[100005];

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

LL in_exclusion(LL sect) {
    LL k, front = 0, sum = 0;
    quu[front++] = -1;
    //所有的素因子都加入队列
    for (LL i = 0; i < (int)primeFactor.size(); ++i) {
        k = front;                          //记录上一次循环的所有因子的组合方式的个数
        for (LL j = 0; j < k; j++)         //用这次的因子a[i]与前面的k中组合进行组合
            quu[front++] = quu[j] * primeFactor[i] * -1; //*(-1)是因为容斥定理 “奇加偶减”性质
    }
    // front为n的素因子的所有可能的组合方式，front = 2^(int)primeFactor.size()-1
    // 这里有效的把二进制位实现的所有种类个数从循环拿到队列中来了
    // 所以这就适用于(int)primeFactor.size()的个数（也可以说n)较大的情况
    for (LL i = 1; i < front; ++i)
        sum += sect/quu[i];
    return sum;  //sum为是n的因子的倍数的个数
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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
        printf("Case #%d: %lld\n", i, B-in_exclusion(B)-(A-1-in_exclusion(A-1)));
        primeFactor.clear();
    }
    return 0;
}
