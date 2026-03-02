/*----------------------------------------------------------------
 *
 *   文件名称：1011.cpp
 *   创建日期：2020年10月19日 ---- 23时44分
 *   结束日期：2020年10月19日 ---- 23时55分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
typedef long long ill;
int count = 0;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        ill A;
        ill B;
        ill C;
        scanf("%lld", &A);
        scanf("%lld", &B);
        scanf("%lld", &C);
        if (A + B > C)
            printf("Case #%d: true\n", ++count);
        else
            printf("Case #%d: false\n", ++count);
    }
    return 0;
}
