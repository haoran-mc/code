/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月29日 星期六 01时59分13秒
 *   题    目：AcWing 0102 最佳牛围栏
 *   算    法：二分，前缀和
 *   描    述：题目描述：从一组数中挑出一段连续的数，这段连续的数
 *          个数大于等于F，然后算出平均值，对于这一段数的平均值算
 *          出后继续算其他的连续的数，找到最大的平均值
 *      1. 使用二分，将最优化问题转化为判定问题，二分答案(答案的
 *          范围给出)，看这组数中是否存在一段数的平均值大于等于mid
 *      2. 对于平均数操作的技巧：将所有的数减去mid，也就是将原问题
 *          是否存在一段数使平均数大于等于mid转化成是否存在一段数
 *          的和是非负的，这里又能用到前缀和
 *      3. 设以j点为右端点，也就是判定[j-F+1, j], [j-F, j],
 *          [j-F-1, j], ... , [0, j]这些区间之中是否存在一个区间的
 *          和是否为非负的
 *          根据前缀和，问题就变成了(preS[j] - preS[j-F+1]), ... 是
 *          否为非负的，也就是是否在[0, j-F+1]的范围内存在一个前缀
 *          和是小于等于preS[j]的，这里也可以用一个数组存储，avg[j]
 *          表示的是[0, j-F+1]的范围内最小的前缀和
 *
 *      涉及到前缀和问题时，数组从1开始，因为preS[0] = 0，不用考虑
 *      边界问题
 *      而且preS[1] = preS[0] + arr[1]，如果从0开始，preS[0]还要另外
 *      判断
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const double eps = 1e-5;
int N, F;
int cows[maxn];
double preS[maxn];

bool judge(double avg) {
    for (int i = 1; i <= N; ++i)
        preS[i] = preS[i-1] + cows[i] - avg;

    double mini = 0; // ?
    for (int i = 0, j = F; j <= N; ++j, ++i) {
        mini = min(mini, preS[i]);
        if (preS[j] >= mini)
            return true;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &N, &F);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &cows[i]);
    //mid是平均值，每个数最大是2000，所以平均值能达到的也就是2000
    double l = 0, r = 2000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", int(r * 1000)); //这里是r
    return 0;
}
