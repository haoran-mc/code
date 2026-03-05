#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
int num[maxn];

void quickSort(int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = num[l + r >> 1];
    int cnt = 0;
    while (i < j) {
        do ++i; while (num[i] < x);
        do --j; while (num[j] > x);
        if (i < j) swap(num[i], num[j]);
    }
    if (num[j] == x && j == k - 1 || num[j+1] == x && j + 1 == k - 1)
        return ;
    if (num[j] == x && j >= k)
        quickSort(l, j);
    else if (num[j+1] == x && j+1 >= k)
        quickSort(l, j+1);
    else
        quickSort(j+1, r);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    quickSort(0, n-1);
    printf("%d\n", num[k-1]);
    return 0;
}
