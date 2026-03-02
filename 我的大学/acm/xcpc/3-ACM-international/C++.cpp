#include <cstdio>
#include <cmath>

typedef long long ill;
ill ans;//逆序对数量
const int maxn = 1e5 + 1;
int uper[maxn];
int down[maxn];
int mp[maxn];

void msort(int left, int right) {
    if (left == right)
        return;

    int mid = (left + right) >> 1;
    msort(left, mid);
    msort(mid + 1, right);
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (uper[i] <= uper[j])
            down[k++] = uper[i++];

        else {
            down[k++] = uper[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid)
        down[k++] = uper[i++];

    while (j <= right)
        down[k++] = uper[j++];

    for (i = left; i <= right; i++)
        uper[i] = down[i];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            mp[num] = i;
        }
        for (int i = 0; i < n; ++i) {
            int num;
            scanf("%d", &num);
            uper[i] = mp[num];
        }
        ans = 0;
        msort(1, n);
        printf("%lld\n", ans);
    }
}
