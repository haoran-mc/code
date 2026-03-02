#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
struct arrage {
    int start;
    int end;
} arr[maxn];

bool cmp(arrage arr1, arrage arr2) {
    return arr1.end < arr2.end;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &arr[i].start, &arr[i].end);
        sort(arr, arr + n, cmp);
        int right = -1;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i].start > right)
                right = arr[i].end,
                ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
