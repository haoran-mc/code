/*----------------------------------------------------------------
 *
 *   文件名称：A--.cpp
 *   创建日期：2020年11月06日 ---- 21时48分
 *   题    目：newcoder
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>

int getexpo(int n) {
    int expo = 1;
    int res  = 0;
    while (expo <= n) {
        expo *= 2;
        ++res;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    int XOR = 0;
    for (int i = 1; i <= t; ++i) {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        int expo = getexpo(n);
        if (m >= expo)
            XOR ^= i;
        else
            XOR ^= (i-1);
    }
    printf("%d\n", XOR);
    return 0;
}
