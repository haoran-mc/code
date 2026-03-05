/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月03日 星期四 17时22分35秒
 *   题    目：AcWing 0109 天才ACM
 *   算    法：<++>
 *   描    述：没用倍增，超时了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 500005;
int n, m;
ll T, I[maxn], tmp[maxn];  //tmp用于求校验值

// 求原数组区间 [l, r] 的校验值
ll get(int l, int r) {
    int idx = 0;        // 要先把 w 的 [l, r] 这段复制到 t 中，用 idx 记录 t 的长度。
    for (int i = l; i <= r; ++i) // 从 l 到 r 枚举一遍，将 w 数组复制到 t 数组中
        tmp[idx++] = I[i];
    sort(tmp, tmp + idx);   // 将复制过来的数排序
    ll sum = 0;       // 存返回的校验值
    for (int i = 0; i < m && i < idx; ++i, --idx)
        sum += pow((tmp[i] - tmp[idx-1]), 2); // 双指针，i 指向当前集合中剩余的最小数，idx 指向当前集合中剩余的最大数
    return sum;
}

int main() {
    int k;            // 测试数据组数
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d %lld", &n, &m, &T);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &I[i]);
        int res = 0;      // 答案归零
        int st = 0;    // st记录当前剩余的区间左端点
        while (st < n) { // st < n 说明当前数组还有值，需要继续划分。结束时 st 应等于 n
            int l = st, r = n; // 二分求出当前能划分的最长的区间
            while (l < r) {
                int mid = (l + r) >> 1;
                if (get(st, mid) > T)
                    r = mid;
                else
                    l = mid + 1;
            }
            st = r;    // 二分完后，r 即当前可划分的最长区间的下一个位置，将 st 制为 r。
            res++;      // 每次划分完一个区间，res ++
        }
        printf("%d\n", res);
    }
    return 0;
}
