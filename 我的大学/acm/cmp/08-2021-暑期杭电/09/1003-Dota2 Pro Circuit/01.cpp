#include <cstdio>
#include <cstring>
const int maxn = 5000 + 5;
int a[maxn], b[maxn];
int maxi[maxn], mini[maxn];
int ha[maxn];

int lowerBound(int l, int r, int val) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] < val || ha[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int upperBound(int l, int r, int val) {
    while (l < r) {
        //这里要加一
        int mid = (l + r + 1) >> 1;
        if (b[mid] <= val || ha[mid])
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t; scanf("%d", &t);
    while (t --) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);

        for (int i = 0; i < n; ++i) {
            int score = 0, cnt = 1;
            memset(ha, 0, sizeof ha);
            score = a[i] + b[0];   // 最高分自然是拿到b[0]
            ha[0] = true;          // 标记这个数已被用过
            int hh = 1, tt = n-1;
            for (int j = 0; j < n; ++j)
                if (j != i) {
                    if (a[j] + b[tt] > score) {   // 如果加上一个最小的数都比i的分数高，不可能会比i的分低了
                        ha[hh++] = true;  // 把现存的最大的数拿掉
                        continue;
                    }
                    int k = lowerBound(0, n-1, score - a[j]);
                    cnt++;  // 前进一名
                    ha[k] = true;
                    if (hh == k)
                        hh ++;
                    if (tt == k)
                        tt --;
                    /*
                     * for (int k = 0; k < n; ++k)    // 否则就遍历b，直到找到第一个小的数
                     *     if (!ha[k] && a[j] + b[k] <= score) {
                     *         cnt++;  // 前进一名
                     *         ha[k] = true;
                     *         if (hh == k)
                     *             hh ++;
                     *         if (tt == k)
                     *             tt --;
                     *     }
                     */
                }
            maxi[i] = n - cnt + 1;   // i的最高排名是cnt
        }

        // 得到最小排名，要让别人的数更高
        for (int i = 0; i < n; ++i) {
            int score = 0, cnt = 1;   // cnt是多少个比自己高的
            memset(ha, 0, sizeof ha);
            score = a[i] + b[n-1];   // 最低分自然是拿到b[n-1]
            ha[n-1] = true;            // 标记这个数已被用过
            int hh = 0, tt = n-1;
            for (int j = 0; j < n; ++j)
                if (j != i) {
                    if (a[j] + b[hh] < score) {     // 如果加上一个最大的数都比i的分数低，不可能会比i的分高了
                        ha[tt--] = true;   // 把现存的最小的数拿走
                        continue;
                    }
                    int k = upperBound(0, n-1, score - a[j]);
                    cnt++;  // 前进一名
                    ha[k] = true;
                    if (hh == k)
                        hh ++;
                    if (tt == k)
                        tt --;
                    /*
                     * for (int k = n-1; k >= 0; --k)    // 否则就倒序遍历b，直到找到第一个大的数
                     *     if (!ha[k] && a[j] + b[k] >= score) {
                     *         cnt++;  // 前进一名
                     *         ha[k] = true;
                     *         if (hh == k)
                     *             hh ++;
                     *         if (tt == k)
                     *             tt --;
                     *     }
                     */
                }
            mini[i] = cnt;   // 有这些个人比i分高
        }
        for (int i = 0; i < n; ++i)
            printf("%d %d\n", maxi[i], mini[i]);
    }
    return 0;
}
