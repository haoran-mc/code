#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;
int a[maxn], b[maxn], res[maxn], n;

bool compare(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// [0, r)
void insertSort(int a[], int i) {
    int insertNum = a[i];

    // 挪动第 i 个数
    int j = i - 1;
    for (; j >= 0; j--) {
        if (insertNum < a[j]) {
            a[j + 1] = a[j];
        } else {
            break;
        }
    }
    a[j + 1] = insertNum;
}

void printArr(int a[], int l, int r) {
    for (int i = l; i < r - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[r - 1]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &res[i]);
    }

    // insert
    for (int i = 1; i < n; i++) {
        insertSort(a, i);

        if (compare(a, res, n)) {
            insertSort(a, i + 1);
            printf("Insertion Sort\n");
            printArr(a, 0, n);
            return 0;
        }
    }

    // merge
    for (int step = 2; step < n; step *= 2) {

        for (int i = 0; i < n; i += step) {
            sort(b + i, b + min(i + step, n));
        }

        if (compare(b, res, n)) {
            step *= 2;
            for (int i = 0; i < n; i += step) {
                sort(b + i, b + min(i + step, n));
            }

            printf("Merge Sort\n");
            printArr(b, 0, n);
            return 0;
        }
    }

    return 0;
}
