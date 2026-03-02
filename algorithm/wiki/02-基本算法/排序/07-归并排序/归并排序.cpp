// 2021年08月08日 星期日 23时51分53秒

#include <cstdio>
int n = 10;
int num[] = {6, 3, 8, 9, 4, 1, 5, 0, 2, 7};

void mergeSort(int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    int tmp[10];
    // v         v
    // -------------------
    int i = l, j = mid + 1, k = 0;
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
    mergeSort(0, n - 1);
    for (int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}
