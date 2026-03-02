#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2005;
struct section {
    int left;
    int right;
} sect[maxn];
// 前i个活动能获得的最长的活动时间
// 01背包中是二维数组是因为有背包容量限制，而此题没有时间限制
// 活动安排时间可任意长
int dp[maxn];

bool cmp(section sect1, section sect2) {
    return sect1.right < sect2.right;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &sect[i].left, &sect[i].right);
    sort(sect, sect+n, cmp);
    dp[0] = sect[0].right - sect[0].left;
    for (int i = 1; i < n; ++i) {
        int maxSect = sect[i].right - sect[i].left;
        for (int j = 0; j < i; ++j)
            if (sect[j].right < sect[i].left)
                maxSect = max(maxSect, dp[j] + sect[i].right - sect[i].left);
        dp[i] = maxSect; // 前i个活动能获得的最长的活动时间
    }
    int maxR = 0;
    for (int i = 0; i < n; ++i)
        maxR = max(maxR, dp[i]);
    printf("%d\n", maxR);
    return 0;
}
