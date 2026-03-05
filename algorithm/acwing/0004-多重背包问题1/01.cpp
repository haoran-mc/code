/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年03月30日 ---- 20时54分
 *   题    目：AcWing 0004 多重背包问题1
 *   算    法：多重背包
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//虽然题目的N <= 100，但二进制分组后会变多，所以需要更多存储空间
const int maxn = 1005;
struct Bone {
    int vol;
    int val;
} bone[maxn];
int N, V;
int dp[maxn];

int main() {
    scanf("%d %d", &N, &V);
    int idx = 1;
    for (int i = 1; i <= N; ++i) {
        int vo, va, k;
        scanf("%d %d %d", &vo, &va, &k);
        int b = 1; //二进制分组，1, 2, 4, 8, 16, ...
        while (k - b > 0) {
            k -= b;
            bone[idx].vol = b * vo;
            bone[idx].val = b * va;
            ++idx;
            b *= 2;
        }
        bone[idx].vol = k * vo;
        bone[idx].val = k * va;
        ++idx;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < idx; ++i)
        for (int j = V; j >= bone[i].vol; --j)
            dp[j] = max(dp[j], dp[j-bone[i].vol] + bone[i].val);
    printf("%d\n", dp[V]);
    return 0;
}
