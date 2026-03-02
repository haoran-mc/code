/*----------------------------------------------------------------
 *
 *   文件名称：05.cpp
 *   创建日期：2021年04月29日 ---- 17时25分
 *   题    目：cf
 *   算    法：<++>
 *   描    述：数组循环遍历了，太棒了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int arr[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        long long sum = 0;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for (int i = 0, j = 1; arr[i]%j == 0; ++i, i %= n) {
            sum += arr[i];
            if (i + 1 == n)
                j *= x;
        }
        printf("%lld\n", sum);
    }
}
