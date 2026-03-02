/*
 *【问题描述】陈老师是一个比赛队的主教练，有一天，他想给团队成员开会，应该为这次会 议安排教室，但教室缺乏，所以教室管理员必须通过接受订单和拒绝订单优化教室的利用率。
 * 如果接受一个订单，则该订单 的开始时间和结束时间成为一个活动。注意，每个时间段只 能安排一个订单，一个活动结束，另一个活动可以马上开始。请找出一个最大化的总活动时间的方法。
 * 你的任务是这样的：读入订单， 计算所有活动（接受的订单）占用时间的最大值。
 *
 * 输入描述：标准等的输入将包含多个测试用例。对于每个测试用例，第 1 行是一个整数 n(n<=2000)，接着的 n 行中每一行包括两个整数 p 和 k（1<=p<=k<=50000）,其中 p 是一 个订单的开始时间，k 是结束时间。
 *
 * 输出描述：对于每个测试用例，输出所有活动占用时间的最大值。
 *
 * 输入样例：
 * 4
 * 1 2
 * 3 5
 * 1 4
 * 4 5
 * 样例输出：
 * 4
 */

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2100;
struct section {
    int left;
    int right;
} sect[maxn];
int dp[maxn];           //dp[i]为前i个活动能获得的最长活动时间
int n;

bool cmp(section x, section y) {
    return x.right < y.right;
}

int DP() {
    dp[0] = sect[0].right - sect[0].left;
    for(int i = 1; i < n; i++) {
        int max_res = sect[i].right - sect[i].left;
        for(int j = 0; j < i; j++)
            if(sect[j].right <= sect[i].left && dp[j] + sect[i].right - sect[i].left > max_res)
                max_res = dp[j] + sect[i].right - sect[i].left;
        dp[i] = max_res;
    }
    int max_r = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] > max_r)
            max_r = dp[i];
    return max_r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &sect[i].left, &sect[i].right);
    sort(sect, sect + n, cmp);
    printf("%d", DP());
    return 0;
}
