/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年08月06日 星期五 19时43分17秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
const int maxn = 1e5 + 5;
int stk[maxn], tt;

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        if (a > stk[tt]) {
            if (!tt)
                printf("-1 ");
            else
                printf("%d ", stk[tt]);
            stk[++tt] = a;
        }
        else {
            while (stk[tt] >= a && tt)
                tt--;
            if (!tt)
                printf("-1 ");
            else
                printf("%d ", stk[tt]);
            stk[++tt] = a;
        }
    }
    return 0;
}
