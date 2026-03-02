/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年05月30日 星期日 01时07分06秒
 *   题    目：AcWing 0787 归并排序
 *   算    法：归并排序
 *   描    述：去看笔记
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
int num[maxn];
int tmp[maxn];

void mergeSort(int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    // v         v
    // -------------------
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (num[i] <= num[j])
            tmp[k++] = num[i++];
        else
            tmp[k++] = num[j++];

    while (i <= mid)
        tmp[k++] = num[i++];
    while (j <= r)
        tmp[k++] = num[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        num[i] = tmp[j];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    mergeSort(0, n-1);
    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    NEXTLINE;
    return 0;
}
