// × 我觉得这个题目不合理，我的归并排序取区间时 mid = (l+r) >> 1 还是 mid = ((l+r) >> 1) + 1？

#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;
int num[maxn], res[maxn], n;
bool insertSortFind = false;
int mergeSortFind = 0;

bool arrEqual(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void insertSort(int a[]) {
    for (int i = 1; i < n; i++) {
        int insertNum = a[i];

        int j = i - 1;
        for (; j >= 0; j--) {
            if (a[j] > insertNum) {
                a[j + 1] = a[j];
            } else {
                break;
            }
        }
        a[j + 1] = insertNum;

        if (insertSortFind) {
            printf("Insertion Sort\n");
            for (int i = 0; i < n - 1; i++) {
                printf("%d ", a[i]);
            }
            printf("%d\n", a[n - 1]);
            return;
        }
        if (arrEqual(res, a)) {
            insertSortFind = true;
        }
    }
}

void mergeSort(int a[], int l, int r) {
    if (l >= r)
        return;

    int mid = ((l + r) >> 1) + 1;
    mergeSort(a, l, mid - 1);
    mergeSort(a, mid, r);

    // l       mid        r
    int i = l, j = mid, k = 0;
    int tmp[maxn];
    while (i < mid && j <= r) {
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i < mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = tmp[k];

    if (mergeSortFind == 1) {
        printf("Merge Sort\n");
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n - 1]);
        mergeSortFind = 2;
        return;
    }
    if (arrEqual(res, a) && mergeSortFind == 0) {
        mergeSortFind = 1;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &res[i]);
    }

    int a1[maxn], a2[maxn];
    copy(num, num + n, a1);
    copy(num, num + n, a2);

    insertSort(a1);
    mergeSort(a2, 0, n - 1);

    return 0;
}
