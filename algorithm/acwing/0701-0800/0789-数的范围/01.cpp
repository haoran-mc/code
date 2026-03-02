#include <cstdio>
#define bug printf("<-->\n");
const int maxn = 1e5 + 5;
int n, q;
int num[maxn];

// [l, r] --> [l, mid], [mid + 1, r]
int lowerBound(int l, int r, int val) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] < val)
            l = mid + 1;
        else
            r = mid;
    }
    if (num[l] != val)
        return -1;
    else
        return l;
}

// [l, r] --> [l, mid - 1], [mid, r]
int upperBound(int l, int r, int val) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (num[mid] <= val)
            l = mid;
        else
            r = mid - 1;
    }
    if (num[l] != val)
        return -1;
    else
        return l;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    while (q--) {
        int val;
        scanf("%d", &val);
        int lower = lowerBound(0, n-1, val);
        int upper = upperBound(0, n-1, val);
        printf("%d %d\n", lower, upper);
    }
    return 0;
}
