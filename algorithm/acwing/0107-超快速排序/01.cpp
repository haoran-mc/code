#include <cstdio>
typedef long long ll;
const int maxn = 5e5 + 5;
ll num[maxn], tmp[maxn];
ll inverse;

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
            /*
             * --------i---------------------
             * ---------------------j--------
             *  num[i] > num[j]
             *  必有num[i+1], num[i+2], ... num[mid] > num[j]
             *  这些对都是逆序对
             */
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
    int n;
    while (scanf("%d", &n) && n) {
        inverse = 0;
        for (int i = 0; i < n; ++i)
            scanf("%lld", &num[i]);
        mergeSort(0, n - 1);
        printf("%lld\n", inverse);
    }
    return 0;
}
