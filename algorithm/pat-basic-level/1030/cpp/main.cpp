#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;
int arr[maxn];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);

    int res = 1;
    for (int i = 0; i < n; i++) {
        int idx = upper_bound(arr, arr + n, (long long)arr[i] * p) - arr;
        // printf("%d %d %lld %d\n", i, arr[i], (long long)arr[i] * p, idx);
        res = max(res, idx - i);
    }

    printf("%d\n", res);
    return 0;
}
