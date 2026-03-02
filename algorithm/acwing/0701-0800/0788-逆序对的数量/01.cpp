#include <cstdio>
#define NEXTLINE puts("");
const int maxn = 1e5 + 5;
int n;
int num[maxn];
int tmp[maxn];
long long inverse;

void mergeSort(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    // v         v
    // -------------------
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (num[i] <= num[j])
            tmp[k++] = num[i++];
        else {
            tmp[k++] = num[j++];
            inverse += (long long)(mid - i + 1);  //只是在归并排序上添加这句
        }

    while (i <= mid)
        tmp[k++] = num[i++];
    while (j <= r)
        tmp[k++] = num[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        num[i] = tmp[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    mergeSort(0, n-1);
    /*
     * for (int i = 0; i < n; ++i)
     *     printf("%d ", num[i]);
     * NEXTLINE;
     */
    printf("%lld\n", inverse);
    return 0;
}
