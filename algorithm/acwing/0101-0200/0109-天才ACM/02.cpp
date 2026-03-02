/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年06月03日 星期四 22时07分49秒
 *   题    目：AcWing 0109 天才ACM
 *   算    法：倍增
 *   描    述：区间是左闭右开的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, m;
ll T, I[maxn], tmp[maxn];

// 计算原数组左闭右开区间 [l, r) 的校验值
ll judge(int l, int r) {
    int idx = 0;
    for (int i = l; i < r; i++)
        tmp[idx++] = I[i];
    sort(tmp, tmp + idx);
    ll sum = 0;
    for (int i = 0; i < m && i < idx; i++, idx--)
        sum += pow((tmp[i] - tmp[idx-1]), 2);
    return sum;
}

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d %lld\n", &n, &m, &T);
        for (int i = 0; i < n; i++)
            scanf("%lld", &I[i]);
        int res = 0;
        int st = 0, ed = 0; // st 记录剩余区间开头节点，ed 记录当前考虑区间的尾结点（左闭右开）
        while (ed < n) {
            int len = 1; // len 初始化为 1
            while (len) { // len 为 0 自动跳出
                // 如果说 len + ed 还在 n 以内，且区间 [st, ed + len) 的校验值不大于 T
                if (ed + len <= n && judge(st, ed + len) <= T)
                    ed += len, len <<= 1;
                else
                    len >>= 1;
            }
            //让st 指向当前区间末尾结点的下一个位置，由于区间是左闭右开的，所以直接指向 ed 就可以了
            st = ed;
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
