/*----------------------------------------------------------------
 *   
 *   文件名称：02.cpp
 *   创建日期：2021年08月24日 星期二 23时06分17秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：太暴力了
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
const int maxn = 1e3 + 5;
int n, a[maxn];

void solve(int i) {
    if (!i)
        i += 2;
    for ( ; i < n; i += 2) 
        if (a[i] > a[i + 1])
            std::swap(a[i], a[i + 1]);
}

bool judge() {
    for (int i = 1; i < n; ++i)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 1; ; ++i) {
            if (judge()) {
                printf("%d\n", res);
                break;
            }
            solve(i & 1);
            res ++;
        }
    }
    return 0;
}
