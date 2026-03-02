/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年11月06日 ---- 20时36分
 *   题    目：newcoder
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    int XOR = 0;
    for (int i = 1; i <= t; ++i) {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);
        if (n & 1)
            --n;
        if (m >= ((n >> 1) + 1))
            XOR ^= i;
        else
            XOR ^= (i-1);
        printf("XOR = %d\n",XOR);
    }
    printf("%d\n", XOR);
    return 0;
}
