#include <cstdio>
const int maxn = 2e5 + 5;
int num[maxn], ha[maxn];
int tmp[maxn];
long long inverse;

void mergeSort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (num[i] <= num[j])
            tmp[k++] = num[i++];
        else {
            tmp[k++] = num[j++];
            inverse += (long long)(mid - i + 1);  
        }

    while (i <= mid)
        tmp[k++] = num[i++];
    while (j <= r)
        tmp[k++] = num[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        num[i] = tmp[j];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
        if (ha[num[i]])    // 如果先前标记这里要++
            num[i]++;
        else {   // 如果先前没有遇到a[i]+1
            ha[num[i]] = 1;
            ha[num[i] - 1] = 1;
        }
    }
    mergeSort(0, n-1);
    printf("%lld\n", inverse);
    // 现在我就得到了一个需要的a数组
    return 0;
}
