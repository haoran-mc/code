#include <algorithm>
#include <cstdio>
const int maxn = 1e5 + 5;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int arr[maxn];
    bool cover[maxn]; // 把所有被覆盖的数标记为 true
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        int j = arr[i];
        while (j != 1) {
            if (j % 2 == 0) {
                j /= 2;
            } else {
                j = (3 * j + 1) / 2;
            }
            cover[j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (cover[arr[i]]) {
            arr[i] = 0;
        }
    }
    std::sort(arr, arr+n);
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            break;
        }
        if ((i > 0 && arr[i-1] == 0) || i == 0) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
