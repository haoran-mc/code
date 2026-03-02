/*----------------------------------------------------------------
 *
 *   文件名称：09-快速排序.cpp
 *   创建日期：2021年05月30日 星期日 00时53分58秒
 *   题    目：AcWing 0785 快速排序
 *   算    法：快速排序
 *   描    述：去看笔记-首元素做基准
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
int num[maxn];

void quickSort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = num[l + r >> 1];
    while (i < j) {
        do i ++ ; while (num[i] < x);
        do j -- ; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }
    //最终i停留在基准上，或者停留在基准的后一个位置
    //最终j停留在基准上，或者停留在基准的前一个位置
    quickSort(l, j);
    quickSort(j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);

    quickSort(0, n-1);
    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    NEXTLINE;
    return 0;
}
