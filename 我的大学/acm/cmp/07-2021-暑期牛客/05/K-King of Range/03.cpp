/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月06日 星期五 20时19分44秒
 *   题    目：AcWing 0154 滑动窗口
 *   算    法：单调队列
 *   描    述：
 *      给定一个大小为 n <= 1e6 的数组。
 *      有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。
 *      你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e6 + 5;
#define NEXTLINE puts("");
int quu[maxn], a[maxn];
int n, k;

void get_min() {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && quu[hh] < i - k + 1)   // 窗口长度不能超过k
            hh++;
        while (hh <= tt && a[quu[tt]] >= a[i])   // a[i]比队尾要小，不断pop
            tt--;
        quu[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[quu[hh]]);   // 队头即为窗口中最小的数
    }
}

void get_max() {
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && quu[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[quu[tt]] <= a[i])
            tt--;
        quu[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[quu[hh]]);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    get_min(); NEXTLINE 
    get_max();
    return 0;
}
